import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash
import datetime

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    user_id = session["user_id"]

    transactions_db = db.execute("SELECT symbol, SUM(shares) AS shares, price FROM transactions WHERE user_id = ? GROUP BY symbol", user_id)
    cash_db = db.execute("SELECT cash FROM users WHERE id = ?", user_id)
    sum_shares = 0

    for row in transactions_db:
        sum_shares += row["shares"] * row["price"]

    cash = cash_db[0]["cash"]
    return render_template("index.html", database=transactions_db, cash=cash, sum_shares=sum_shares)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "GET":
        return render_template("buy.html")
    else:
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")

        if not shares or not shares.isdigit() or int(shares) <= 0:
            return apology("Invalid number of shares")

        shares = int(shares)

        if not symbol:
            return apology("Symbol required")

        stock = lookup(symbol.upper())

        if stock == None:
            return apology("Symbol does not exist")

        if shares < 0:
            return apology("Share not allowed")

        transaction_value = shares * stock["price"]

        user_id = session["user_id"]
        user_cash_db = db.execute("SELECT cash FROM users WHERE id = :id", id=user_id)
        user_cash = user_cash_db[0]["cash"]

        if user_cash < transaction_value:
            return apology("Insufficient Funds")

        updt_cash = user_cash - transaction_value
        db.execute("UPDATE users SET cash = ? WHERE id = ?", updt_cash, user_id)

        date = datetime.datetime.now()
        db.execute("INSERT INTO transactions (user_id, symbol, shares, price, date) VALUES (?, ?, ?, ?, ?)", user_id, stock["symbol"], shares, stock["price"], date)

        flash("Bought!")

        return redirect("/")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    user_id = session["user_id"]
    transactions_db = db.execute("SELECT * FROM transactions WHERE user_id = :id", id=user_id)
    return render_template("history.html", transactions=transactions_db)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "GET":
        return render_template("quote.html")
    else:
        symbol = request.form.get("symbol")

        if not symbol:
            return apology("Symbol required")

        stock = lookup(symbol.upper())

        if stock == None:
            return apology("Symbol does not exist")

        return render_template("quoted.html", name=stock["name"], price=stock["price"], symbol=stock["symbol"])


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "GET":
        return render_template("register.html")
    else:
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")

        if not username:
            return apology("An username is required")

        if not password:
            return apology("A password is required")

        if not confirmation:
            return apology("A confirmation is required")

        if password != confirmation:
            return apology("Passwords do not match")

        hash = generate_password_hash(password)

        try:
            new_user = db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", username, hash)
        except:
            return apology("Username already exists")

        session["user_id"] = new_user

        return redirect("/")


@app.route("/add_cash", methods=["GET", "POST"])
@login_required
def add_cash():
    """Allows user to add more cash"""
    if request.method == "GET":
        return render_template("add.html")
    else:
        new_cash = int(request.form.get("new_cash"))

        if not new_cash:
            return apology("Adding money is required")

        user_id = session["user_id"]
        user_cash_db = db.execute("SELECT cash FROM users WHERE id = :id", id=user_id)
        user_cash = user_cash_db[0]["cash"]

        user_shares = db.execute("SELECT SUM(shares) AS shares FROM transactions WHERE user_id=:id AND symbol = :symbol", id=user_id, symbol=symbol)
        user_shares_real = user_shares[0]["shares"]

        updt_cash = user_cash + new_cash
        db.execute("UPDATE users SET cash = ? WHERE id = ?", updt_cash, user_id)

        return redirect("/")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method == "GET":
        user_id = session["user_id"]
        symbols_user = db.execute("SELECT symbol FROM transactions WHERE user_id = :id GROUP BY symbol HAVING SUM(shares) > 0", id=user_id)
        return render_template("sell.html", symbols=[row["symbol"] for row in symbols_user])
    else:
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")

        if not shares or int(shares) <= 0:
            return apology("Invalid number of shares")

        shares = int(shares)

        if not symbol:
            return apology("Symbol required")

        stock = lookup(symbol.upper())

        if stock is None:
            return apology("Symbol does not exist")

        user_id = session["user_id"]
        user_cash_db = db.execute("SELECT cash FROM users WHERE id = :id", id=user_id)
        user_cash = user_cash_db[0]["cash"]

        user_shares = db.execute("SELECT SUM(shares) AS shares FROM transactions WHERE user_id=:id AND symbol = :symbol", id=user_id, symbol=symbol)
        user_shares_real = user_shares[0]["shares"]

        if shares > user_shares_real:
            return apology("Insufficient amount of shares")

        transaction_value = shares * stock["price"]

        updt_cash = user_cash + transaction_value
        db.execute("UPDATE users SET cash = ? WHERE id = ?", updt_cash, user_id)

        date = datetime.datetime.now()
        db.execute("INSERT INTO transactions (user_id, symbol, shares, price, date) VALUES (?, ?, ?, ?, ?)", user_id, stock["symbol"], (-1) * shares, stock["price"], date)

        flash("Sold!")

        return redirect("/")
