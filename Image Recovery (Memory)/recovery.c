#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define FOURTH_BYTE(byte) ((byte) >= 0xe0 && (byte) <= 0xef)
bool check_SOJ(unsigned char *buffer);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Correct Usage: ./recover file_name\n");
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("File could not be opened\n");
        return 1;
    }

    unsigned char buffer[512]; // Buffer to hold bytes
    int file_counter = 0;
    FILE *output = NULL; 

    // Read 512 bytes
    while (fread(buffer, sizeof(unsigned char), 512, input) == 512)
    {
        // Check if the current block is a JPEG header
        if (check_SOJ(buffer))
        {

            if (output != NULL)
            {
                fclose(output);
            }


            char filename[20];
            sprintf(filename, "%03i.jpg", file_counter++);




            output = fopen(filename, "w");
            if (output == NULL)
            {
                printf("Output file could not be created\n");
                fclose(input);
                return 1;
            }
        }

        // If an output file is open, write the buffer to the file
        if (output != NULL)
        {
            fwrite(buffer, sizeof(unsigned char), 512, output);
        }
    }


    if (output != NULL)
    {
        fclose(output);
    }

    fclose(input);
    return 0;
}

// Function to check for the start of a JPEG
bool check_SOJ(unsigned char *buffer)
{
    return buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && FOURTH_BYTE(buffer[3]);
}
