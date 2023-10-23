// RECOVER: https://cs50.harvard.edu/x/2023/psets/4/recover/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define BLOCKSIZE 512

int main(int argc, char *argv[])
{
    // check if file is valid
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("An error has occurred while opening the file.\n");
        return 1;
    }

    typedef uint8_t BYTE;
    char currentFileName[100];
    int currentFileNumber = 0;
    bool foundJPEG = false;
    bool firstJPEG = false;
    BYTE buffer[BLOCKSIZE];
    size_t bytes_read;
    FILE *currentFile;

    // Open memory card
    while (true)
    {
        // Repeat until end of card
        // Read 512 bytes into buffer
        bytes_read = fread(buffer, sizeof(BYTE), BLOCKSIZE, file);
        if (bytes_read == 0)
        {
            break;
        }
        // If start of new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            foundJPEG = true;
            // If first JPEG
            if (!firstJPEG)
            {
                firstJPEG = true;
            }
            else
            {
                // close the current file
                fclose(currentFile);
            }
            sprintf(currentFileName, "%03i.jpg", currentFileNumber); // 001.jpg
            currentFile = fopen(currentFileName, "w");
            fwrite(buffer, sizeof(BYTE), bytes_read, currentFile);
            currentFileNumber++;
        }
        else
        {
            // If already found JPEG
            if (foundJPEG)
            {
                fwrite(buffer, sizeof(BYTE), bytes_read, currentFile);
            }
        }
    }

    // Close any remaining files
    fclose(file); // close raw file
    fclose(currentFile); // close current file
    return 0;
}
