//MARIO-LESS: https://cs50.harvard.edu/x/2023/psets/1/mario/less/

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = 0;
    // ask for a number between 1 and 8
    do
    {
        printf("\nHeight: ");
        scanf("%d", &height);
    }
    while (height < 1 || height > 8);

    // a loop with the size of the input
    for (int i = 0; i < height; i++)
    {
        // creates a space before the #, i = 1 so that the last line is just #
        for (int j = 1; j < height - i; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
