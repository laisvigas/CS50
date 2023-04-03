// FILTER: https://cs50.harvard.edu/x/2023/psets/4/filter/less/

#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            float average = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0;

            int roundaverage = round(average);

            image[i][j].rgbtRed = roundaverage;
            image[i][j].rgbtGreen = roundaverage;
            image[i][j].rgbtBlue = roundaverage;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Applying the following algorithm for sepia
            float sepiaRed = (0.393 * image[i][j].rgbtRed) + (0.769 * image[i][j].rgbtGreen) + (0.189 * image[i][j].rgbtBlue);

            float sepiaGreen = (0.349 * image[i][j].rgbtRed) + (0.686 * image[i][j].rgbtGreen) + (0.168 * image[i][j].rgbtBlue);

            float sepiaBlue = (0.272 * image[i][j].rgbtRed) + (0.534 * image[i][j].rgbtGreen) + (0.131 * image[i][j].rgbtBlue);

            //rounding the values
            int rSepiaRed = round(sepiaRed);
            int rSepiaGreen = round(sepiaGreen);
            int rSepiaBlue = round(sepiaBlue);

            // Setting the limit to 255
            if (rSepiaRed > 255)
            {
                rSepiaRed = 255;
            }

            if (rSepiaGreen > 255)
            {
                rSepiaGreen = 255;
            }

            if (rSepiaBlue > 255)
            {
                rSepiaBlue = 255;
            }

            image[i][j].rgbtRed = rSepiaRed;
            image[i][j].rgbtGreen = rSepiaGreen;
            image[i][j].rgbtBlue = rSepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE initialPosition = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = initialPosition;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a temporary copy of the image, looping through each pixel
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int totalRed, totalBlue, totalGreen;
            totalRed = totalBlue = totalGreen = 0;
            float counter = 0.00;

            // Get neighbouring pixels
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int currentX = i + x;
                    int currentY = j + y;

                    // Check if the neighbouring pixel is valid
                    if (currentX < 0 || currentX > (height - 1) || currentY < 0 || currentY > (width - 1))
                    {
                        continue;
                    }

                    // Get image value
                    totalRed += image[currentX][currentY].rgbtRed;
                    totalGreen += image[currentX][currentY].rgbtGreen;
                    totalBlue += image[currentX][currentY].rgbtBlue;

                    counter++;
                }

                // Calculate average of neighbouring pixels
                copy[i][j].rgbtRed = round(totalRed / counter);
                copy[i][j].rgbtGreen = round(totalGreen / counter);
                copy[i][j].rgbtBlue = round(totalBlue / counter);
            }
        }
    }
    // Copy new pixels into original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = copy[i][j].rgbtRed;
            image[i][j].rgbtGreen = copy[i][j].rgbtGreen;
            image[i][j].rgbtBlue = copy[i][j].rgbtBlue;
        }
    }
    return;
}
