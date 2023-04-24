# BANK: https://cs50.harvard.edu/x/2023/problems/6/bank/

greeting = input("Greeting: ").lower().strip()

if greeting[0:5] == "hello":
    print("$0")
elif greeting[0:1] == "h":
    print("$20")
else:
    print("$100")