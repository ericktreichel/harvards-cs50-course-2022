// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdint.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = (200000);
// Counter to the words added from dictionary
int added_words = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // create a variable cursor to help us and put it to the head of our list
    node *cursor = table[hash(word)];
    // loop until we hit the end of the list (cursor = NULL)
    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        // otherwise, move cursor to next node (cursor = cursor->next)
        {
            cursor = cursor->next;
        }
    }
    return false;
}

unsigned int hash(const char *word)
// Hashes word to a number

{
    int hashf = 0;

    for (int i = 0; word[i]; i++)
    {
        hashf += tolower(word[i]) * (i + 1);
    }
    return (hashf % N);

}


// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // Opening the dictionary file and checking if it's NULL or not
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        // printf("Unable to open the file %s\n", dictionary);
        return false;
    }
    /// Read strings from dictionary file one at a time
    // fscanf(file, "%s", word) in a loop, and create a variable to store the scanned words
    /// create a new node for each word
    char next_word[LENGTH + 1];

    // use malloc to allocate memory for these words
    // criar uma variavel temporaria (new_node) do tipo node pra alocar espaço
    while (fscanf(file, "%s", next_word) != EOF)
    {
        node *new_node = malloc(sizeof(node));
        // check if return value is NULL
        if (new_node == NULL)
        {
            return false;
        }
        // copy word into node using strcpy
        strcpy(new_node->word, next_word);

        /// use the hash function to take an word and return an int
        int hash_value = hash(next_word);

        // Inserting the new node into hash table at the location
        new_node->next = table[hash_value];
        table[hash_value] = new_node;
        added_words++;
    }
    // Closing the file
    fclose(file);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    // return our counter from Load step
    // printf("Total words: %i !!!\n", added_words);
    return added_words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    /// Create two variables: cursor and tpm. set both to the head (first element of the linked list)
    /// create a FOR loop, then an IF to check if the list is already NULL or not. if not null, repeat the instructions above,
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        node *temp = cursor;

        while (cursor != NULL)
        {
            cursor = cursor->next;
            free(temp);
            temp = cursor;
        }
        // checking if the conditions are match to return true, othersiwe false
        if (cursor == NULL && i == (N - 1))
        {
            return true;
        }
    }
    return false;
}