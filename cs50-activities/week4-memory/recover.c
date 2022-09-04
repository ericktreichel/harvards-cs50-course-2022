#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>

#define BLOCK_SIZE 512
#define NAME_SIZE 8

typedef uint8_t BYTE;

void checkArgumentCount(int argc);
void checkFileExists(FILE *file);
int isJPG(BYTE buffer[]);

int main(int argc, char *argv[])
{
    checkArgumentCount(argc);
    FILE *raw = fopen(argv[1], "r");
    checkFileExists(raw);

    // Temp buffer to allocate memory and start variables
    BYTE buffer[BLOCK_SIZE];

    // array as a buffer for filename
    char filename[NAME_SIZE];
    FILE *image;
    int counter = 0;

    // Loop to work after the first jpeg is found
    while (fread(buffer, BLOCK_SIZE, 1, raw) == 1)
    {
        if (isJPG(buffer) == 1)
        {
            // End the previous image reading (for the 2nd and subsequent files)
            if (counter != 0)
            {
                fclose(image);
            }
            sprintf(filename, "%03i.jpg", counter++);
            image = fopen(filename, "w");
            fwrite(buffer, BLOCK_SIZE, 1, image);
        }
        // The function will keep written until we find the next JPG header
        else if (counter > 0)
        {
            fwrite(buffer, BLOCK_SIZE, 1, image);
        }
    }
}
// making sure the user passed two arguments
void checkArgumentCount(int argc)
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        exit(1);
    }
}
// making sure the file isn't NULL or corrupted
void checkFileExists(FILE *file)
{
    if (file == NULL)
    {
        printf("The file could not be read.\n");
        exit(1);
    }
}
// code checking by the JPG identifier (first 4 bytes)
int isJPG(BYTE buffer[])
{
    if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && ((buffer[3] & 0xf0) == 0xe0))
    {
        return 1;
    }
    return 0;
}
