#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // sum the values and divide by 3. round the number
            float sum = image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed;
            int average = round(sum / 3);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;

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
            float originalBlue = image[i][j].rgbtBlue;
            float originalGreen = image[i][j].rgbtGreen;
            float originalRed = image[i][j].rgbtRed;
            // apply the formula for sepia
            float sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue;
            float sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue;
            float sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue;
            // check that value dont overpass 255. In case it does, set the value to 255
            image[i][j].rgbtBlue = round(sepiaBlue) > 255 ? 255 : round(sepiaBlue);
            image[i][j].rgbtGreen = round(sepiaGreen) > 255 ? 255 : round(sepiaGreen);
            image[i][j].rgbtRed = round(sepiaRed) > 255 ? 255 : round(sepiaRed);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        RGBTRIPLE buffer[width];

        for (int j = 0; j < width; j++)
        {
            int position = width - j - 1;
            buffer[position] = image[i][j];
        }

        // replace the horizontal line with the buffer
        for (int k = 0; k < width; k++)
        {
            image[i][k] = buffer[k];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float count = 0.0;
            float sumRed = 0;
            float sumBlue = 0;
            float sumGreen = 0;
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int xAxis = i + x;
                    int yAxis = j + y;

                    // check if that position exists
                    if (xAxis < 0 || yAxis < 0 || xAxis > (height - 1) || yAxis > (width - 1))
                    {
                        continue;
                    }

                    // sum all colors
                    sumRed += image[xAxis][yAxis].rgbtRed;
                    sumBlue += image[xAxis][yAxis].rgbtBlue;
                    sumGreen += image[xAxis][yAxis].rgbtGreen;

                    count++;
                }
            }

            // set the blur value
            temp[i][j].rgbtBlue = round(sumBlue / count);
            temp[i][j].rgbtRed = round(sumRed / count);
            temp[i][j].rgbtGreen = round(sumGreen / count);
        }
    }

    // replace the image with the temporary blurred
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }

    return;
}
