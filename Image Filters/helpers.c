#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)  //rows
    {
        for(int j = 0; j < width; j++)  //columns
        {
            BYTE average;
            average = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);

            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)  //each row
    {
        for(int j = 0; j < width / 2; j++)
        {
             RGBTRIPLE temp;
             temp = image[i][width - j - 1];
             image[i][width - j - 1] = image[i][j];
             image[i][j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int sumRed = 0, sumGreen = 0, sumBlue = 0;
            float validPixels = 0.0;

            for(int ni = i-1; ni <= i+1; ni++)
            {
                for(int nj = j-1; nj <= j+1; nj++)
                {
                    if(ni >= 0 && ni < height && nj >= 0 && nj < width)
                    {
                         sumRed += image[ni][nj].rgbtRed;
                         sumGreen += image[ni][nj].rgbtGreen;
                         sumBlue += image[ni][nj].rgbtBlue;
                         validPixels = validPixels + 1.0;
                    }
                }
            }
            temp[i][j].rgbtRed = round(sumRed / validPixels);
            temp[i][j].rgbtGreen = round(sumGreen / validPixels);
            temp[i][j].rgbtBlue = round(sumBlue / validPixels);
        }
    }

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }

    //return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Sobel kernels for Gx and Gy
    int array_gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int array_gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    // Temporary copy of the image to store the new values
    RGBTRIPLE copy[height][width];

    // Loop over each pixel in the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Initialize Sobel filters for each color channel
            int Gx_red = 0, Gy_red = 0;
            int Gx_green = 0, Gy_green = 0;
            int Gx_blue = 0, Gy_blue = 0;

            // Loop over the 3x3 grid of neighbors
            for (int ni = -1; ni <= 1; ni++)
            {
                for (int nj = -1; nj <= 1; nj++)
                {
                    // Neighbor pixel position
                    int row = i + ni;
                    int col = j + nj;

                    // Check if the neighbor pixel is within bounds
                    if (row >= 0 && row < height && col >= 0 && col < width)
                    {
                        // Apply the Sobel kernels to each color channel
                        Gx_red += image[row][col].rgbtRed * array_gx[ni + 1][nj + 1];
                        Gy_red += image[row][col].rgbtRed * array_gy[ni + 1][nj + 1];

                        Gx_green += image[row][col].rgbtGreen * array_gx[ni + 1][nj + 1];
                        Gy_green += image[row][col].rgbtGreen * array_gy[ni + 1][nj + 1];

                        Gx_blue += image[row][col].rgbtBlue * array_gx[ni + 1][nj + 1];
                        Gy_blue += image[row][col].rgbtBlue * array_gy[ni + 1][nj + 1];
                    }
                }
            }

            // Calculate the gradient magnitude for each color channel
            int red_val = round(sqrt(Gx_red * Gx_red + Gy_red * Gy_red));
            int green_val = round(sqrt(Gx_green * Gx_green + Gy_green * Gy_green));
            int blue_val = round(sqrt(Gx_blue * Gx_blue + Gy_blue * Gy_blue));

            // Cap the values at 255
            copy[i][j].rgbtRed = (red_val > 255) ? 255 : red_val;
            copy[i][j].rgbtGreen = (green_val > 255) ? 255 : green_val;
            copy[i][j].rgbtBlue = (blue_val > 255) ? 255 : blue_val;
        }
    }

    // Copy the modified image back to the original image array
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = copy[i][j];
        }
    }
}
