#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    //checking for upper case in first input
    int length = strlen(word1);
    for (int j = 0; j < length; j++)
        if (isupper(word1[j]))
        {
            word1[j] = tolower(word1[j]);
        }

    //checking for upper case in second input
    int length2 = strlen(word2);
    for (int j = 0; j < length2; j++)
        if (isupper(word2[j]))
        {
            word2[j] = tolower(word2[j]);
        }

    // Storing both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Returning the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

}


//Function
int compute_score(string word)
{
    //First try, need to shrink this function
    int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    char letters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int score = 0;

    //Manually assigning the value for each letter of the alphabet
    //and adding a value to SCORE to sum the letters
    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] == 'a')
        {
            score += 1;
        }
    }

    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] == 'b')
        {
            score += 3;
        }
    }

    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] == 'c')
        {
            score += 3;
        }
    }

    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] == 'd')
        {
            score += 2;
        }
    }

    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] == 'e')
        {
            score += 1;
        }
    }

    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] == 'f')
        {
            score += 4;
        }
    }

    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] == 'g')
        {
            score += 2;
        }
    }

    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] == 'h')
        {
            score += 4;
        }
    }

    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] == 'i')
        {
            score += 1;
        }
    }

    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] == 'j')
        {
            score += 8;
        }
    }

    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] == 'k')
        {
            score += 5;
        }
    }

    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] == 'l')
        {
            score += 1;
        }
    }

    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] == 'm')
        {
            score += 3;
        }
    }

    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] == 'n')
        {
            score += 1;
        }
    }

    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] == 'o')
        {
            score += 1;
        }
    }

    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] == 'p')
        {
            score += 3;
        }
    }

    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] == 'q')
        {
            score += 10;
        }
    }

    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] == 'r')
        {
            score += 1;
        }
    }

    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] == 's')
        {
            score += 1;
        }
    }

    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] == 't')
        {
            score += 1;
        }
    }

    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] == 'u')
        {
            score += 1;
        }
    }

    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] == 'v')
        {
            score += 4;
        }
    }

    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] == 'w')
        {
            score += 4;
        }
    }

    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] == 'x')
        {
            score += 8;
        }
    }

    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] == 'y')
        {
            score += 4;
        }
    }

    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] == 'z')
        {
            score += 10;
        }
    }
    return score;
}
