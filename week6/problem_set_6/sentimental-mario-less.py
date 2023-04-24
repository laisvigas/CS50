# MARIO-LESS: https://cs50.harvard.edu/x/2023/psets/6/mario/less/

from cs50 import get_int

height = 0

# prompt the user for a number between 1 and 8
while height < 1 or height > 8:
    height = get_int("Height: ")

# iterating over the number of loops to add one more #
cont = 1

# iterating over the number of loops (starting with height - 1) to subtract one blanket space in front of the #
cont2 = height - 1

for c in range(height):
    print(" " * cont2, end="")
    print("#" * cont)
    cont += 1
    cont2 -= 1
