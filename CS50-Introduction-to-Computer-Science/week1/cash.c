// CASH: https://cs50.harvard.edu/x/2023/psets/1/cash/

#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    // TODO
    int change_owed = 0;
    do
    {
        change_owed = get_int("Change Owed: ");
    }
    while (change_owed < 0);

    return change_owed;
}

int calculate_quarters(int cents)
{
    // TODO
    int coin_count = 0;
    while (cents >= 25)
    {
        coin_count += 1;
        cents -= 25;
    }
    return coin_count;
}

int calculate_dimes(int cents)
{
    // TODO
    int coin_count = 0;
    while (cents >= 10)
    {
        coin_count += 1;
        cents -= 10;
    }
    return coin_count;
}

int calculate_nickels(int cents)
{
    // TODO
    int coin_count = 0;
    while (cents >= 5)
    {
        coin_count += 1;
        cents -= 5;
    }
    return coin_count;
}

int calculate_pennies(int cents)
{
    // TODO
    int coin_count = 0;
    while (cents >= 1)
    {
        coin_count += 1;
        cents -= 1;
    }
    return coin_count;
}
