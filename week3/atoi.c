#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    int string_length = strlen(input);
    if (string_length == 1)
    {
        return input[0] - 48;
    }

    char last_string_digit = input[string_length - 1];

    int last_digit = last_string_digit - 48;

    input[string_length - 1] = '\0';

    return last_digit + 10 * (convert(input));
}