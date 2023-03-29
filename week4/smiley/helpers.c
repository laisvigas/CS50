// https://cs50.harvard.edu/x/2023/labs/4/smiley/

#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // TODO: Change all black pixels to a color of your choosing
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (image[i][j].rgbtRed == 0x00 && image[i][j].rgbtGreen == 0x00 && image[i][j].rgbtBlue == 0x00)
            {
                image[i][j].rgbtGreen = 0xff;
            }
        }
    }
}
