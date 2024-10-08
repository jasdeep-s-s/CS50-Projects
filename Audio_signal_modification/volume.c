// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");  //argv[1] is the .wav file and "r" means to read from it
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w"); // "w" means write mode
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    for(int i = 0; i < HEADER_SIZE; i++)
    {
        unsigned char temp;

        //read and write header file
        fread(&temp, 1, 1, input);
        fwrite(&temp, 1, 1, output);

    }

    // TODO: Read samples from input file and write updated data to output file
    fseek(input, 44, SEEK_SET);

    short int temp;

    while(fread(&temp, sizeof(short int), 1, input))
    {
        temp = temp * factor;
        fwrite(&temp, sizeof(short int), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}
