// READABILITY: https://cs50.harvard.edu/x/2023/psets/2/readability/

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string words);
int count_sentences(string words);

//MAIN
int main(void)
{
    string text = get_string("Text: ");
    float l = (100 * ((float) count_letters(text) / (float) count_words(text)));
    float s = (100 * ((float) count_sentences(text) / (float) count_words(text)));
    //Coleman-Liau index
    float coleman_liau = (0.0588 * l) - (0.296 * s) - 15.8;
    int cl = (round(coleman_liau));

    if (cl >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (cl < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", cl);
    }
    //printf("%d letters\n", count_letters(text));
    //printf("%d words\n", count_words(text));
    //printf("%d sentences\n", count_sentences(text));
}


//function to count only letters
int count_letters(string text)
{
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }

    return count;
}

//function to count the words
//words like sister-in-law is considered to be one word
int count_words(string words)
{
    int len = strlen(words);
    int count = 0;
    char nonwords[] = " .,;\n\t";

    for (int i = 0; i < len; i++)
    {
        while (i < len)
        {
            if (strchr(nonwords, words[i]) != NULL)
            {
                break;
            }
            i++;
        }

        count++;

        while (i < len)
        {
            if (strchr(nonwords, words[i]) == NULL)
            {
                break;
            }
            i++;
        }
    }
    return count;
}

//function to count the sentences
int count_sentences(string words)
{
    int len = strlen(words);
    int count = 0;
    char nonwords[] = ".!?";

    for (int i = 0; i < len; i++)
    {
        while (i < len)
        {
            if (strchr(nonwords, words[i]) != NULL)
            {
                break;
            }
            i++;
        }

        count++;

        while (i < len)
        {
            if (strchr(nonwords, words[i]) == NULL)
            {
                break;
            }
            i++;
        }
    }
    return count;
}
