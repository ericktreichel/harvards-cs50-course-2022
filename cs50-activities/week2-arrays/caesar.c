#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
//checking whether user put two arguments or not
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
//looping to make sure the second input is a digit
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
// converting the argv[1] entry to int
    int key = atoi(argv[1]);
// asking user's input
    string input = get_string("plaintext:  ");
// returning the ciphertext
    printf("ciphertext: ");
// for loop inside all characters lower and uppercase applying the key
    for (int j = 0; j < strlen(input); j++)
    {
        if (isupper(input[j]))
        {
            printf("%c", (input[j] - 65 + key) % 26 + 65);
        }
        else if (islower(input[j]))
        {
            printf("%c", (input[j] - 97 + key) % 26 + 97);
        }
        else
        {
            printf("%c", input[j]);
        }
    }
    printf("\n");
}
