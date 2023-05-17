// Implements a dictionary's functionality
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

int wordCount = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int hashValue = hash(word);

    node *n = table[hashValue];

    while (n != NULL)
    {
        if (strcasecmp(word, n->word) == 0)
        {
            return true;
        }

        n = n->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    long sum = 0;

    for (int i = 0; i < strlen(word); i++)
    {
        sum += tolower(word[i]);
    }
    return sum % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    char nextWord[LENGTH + 1];

    // Read strings from file one at a time
    while (fscanf(file, "%s", nextWord) != EOF)
    {
        // Create new node for each word
        node *newNode = malloc(sizeof(node));
        if (newNode == NULL)
        {
            return false;
        }

        strcpy(newNode->word, nextWord);

        int hashValue = hash(nextWord);
        newNode->next = table[hashValue];
        table[hashValue] = newNode;
        wordCount++;
    }
    // Close file
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return wordCount++;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i<N; i++)
    {
        node *n = table[i];
        node *temp = n;

        while (n != NULL)
        {
            n = n->next;
            free(temp);
            temp = n;
        }
    }

    return true;
}