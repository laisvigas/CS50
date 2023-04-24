# TAQUERIA: https://cs50.harvard.edu/x/2023/problems/6/taqueria/

menu = {
    "Baja Taco": 4.00,
    "Burrito": 7.50,
    "Bowl": 8.50,
    "Nachos": 11.00,
    "Quesadilla": 8.50,
    "Super Burrito": 8.50,
    "Super Quesadilla": 9.50,
    "Taco": 3.00,
    "Tortilla Salad": 8.00
    }

total = 0

while True:
    try:
        addedItem = str(input("Item: ")).strip().title()
        if addedItem in menu:
            total += menu[addedItem]
            print(f"Total: ${total:.2f}")
    except EOFError:
        break
