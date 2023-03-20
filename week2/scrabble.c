// SCRABBLE: https://cs50.harvard.edu/x/2023/labs/2/

#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
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

int compute_score(string word)
{

    // TODO: Compute and return score for string
    char letters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char letters_upper[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    //Array to save the poits
    int letters_count[strlen(word)];

    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < strlen(word); j++)
        {
            //considering only alphabet characters
            if (isalpha(word[j]))
            {
                //checking if the current letter equals the same one in the LETTERS and LETTERS_UPPER
                //if so, assign the same index of POINTS to WORDS in order to get the points
                if (word[j] == letters[i] || word[j] == letters_upper[i])
                {
                    letters_count[j] = POINTS[i];
                }
            }
            // if it's not alphabetic, assigned value of zero
            else
            {
                word[j] = 0;
            }
        }
    }

    // returning the sum of the array
    int sum = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        sum += letters_count[i];
    }

    return sum;
}

