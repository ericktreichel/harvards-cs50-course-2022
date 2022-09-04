#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
//    int sum[height][width];
//    float average[height][width];
    // looping for each row (height)
    for (int i = 0; i < (height); i++)
    {
        // looping for each column (width)
        for (int j = 0; j < (width); j++)
        {
            // Converting pixels to float
            float Red = image[i][j].rgbtRed;
            float Green = image[i][j].rgbtGreen;
            float Blue = image[i][j].rgbtBlue;

            // Defining and applying the average value for the pixels
            int average = round((Red + Green + Blue) / 3);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = average;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < (height); i++)
    {
        for (int j = 0; j < (width); j++)
        {
            // Convertir pixels to float
            float Red = image[i][j].rgbtRed;
            float Green = image[i][j].rgbtGreen;
            float Blue = image[i][j].rgbtBlue;

            // Calculating the sepia values to each color based in the formula
            int sepiaRed = round((0.393 * Red) + (0.769 * Green) + (0.189 * Blue));
            int sepiaGreen = round((0.349 * Red) + (0.686 * Green) + (0.168 * Blue));
            int sepiaBlue = round((0.272 * Red) + (0.534 * Green) + (0.131 * Blue));

            // Applying the sepia values to the pixels for both cases (limiting  it to 255 if higher)
            if (sepiaRed >= 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = sepiaRed;
            }

            if (sepiaGreen >= 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = sepiaGreen;
            }

            if (sepiaBlue >= 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // looping throught the height
    for (int i = 0; i < (height - 0); i++)
    {
        // looing throught the width until width/2 (center of the picture)
        for (int j = 0; j < (width / 2) ; j++)
        {
            // creating an temporary array arr to store image[i][j]
            RGBTRIPLE arr = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = arr;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // temporary array to store the calculated values
    // looping throught the rows and columns
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }


    // looping throught the rows and columns
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // declaring new 'total' variables to store the total of each color around every pixel
            // and declaring the counter to help calculate the average
            int totalRed, totalGreen, totalBlue;
            totalRed = totalGreen = totalBlue = 0;
            float counter = 0.0;
            // getting the neighbor pixels
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int currentX = i + x;
                    int currentY = j + y;

                    // checking if the neighbor pixels are valid
                    if (currentX < 0 || currentX > (height - 1) || currentY < 0 || currentY > (width - 1))
                    {
                        continue;
                    }
                    // Getting image value for each color
                    totalRed += image[currentX][currentY].rgbtRed;
                    totalGreen += image[currentX][currentY].rgbtGreen;
                    totalBlue += image[currentX][currentY].rgbtBlue;
                    // counter to store how many pixels are being added to the average
                    counter++;
                }
                // Calculating average of the neighbor pixels
                temp[i][j].rgbtRed = round(totalRed / counter);
                temp[i][j].rgbtGreen = round(totalGreen / counter);
                temp[i][j].rgbtBlue = round(totalBlue / counter);
            }
        }
    }

    // Applying the new values to the original image pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }

    return;
}

