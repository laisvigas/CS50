# CASH: https://cs50.harvard.edu/x/2023/psets/6/cash/

from cs50 import get_float

def main():
    coins = give_change()

    quarters = calculate_quarters(coins)
    coins -= quarters * 25

    dimes = calculate_dimes(coins)
    coins -= dimes * 10

    nickels = calculate_nickels(coins)
    coins -= nickels * 5

    pennies = calculate_pennies(coins)
    coins -= pennies * 1

    troco = quarters + dimes + nickels + pennies

    print(troco)


def calculate_quarters(cents):
    coin_count = 0
    while cents >= 25:
        coin_count += 1
        cents -= 25
    return coin_count


def calculate_dimes(cents):
    coin_count = 0
    while cents >= 10:
        coin_count += 1
        cents -= 10
    return coin_count


def calculate_nickels(cents):
    coin_count = 0
    while cents >= 5:
        coin_count += 1
        cents -= 5
    return coin_count


def calculate_pennies(cents):
    coin_count = 0
    while cents >= 1:
        coin_count += 1
        cents -= 1
    return coin_count


def give_change():
    while True:
        coins = get_float("Change owed: ")
        if coins >= 0:
            break
    cents = coins * 100
    return cents


main()
