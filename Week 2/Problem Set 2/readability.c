#include <ctype.h>
#include <math.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// since you can't return arrays from functions in C, I decided to create 3 functions that loop through the same array
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    float L = ((float) letters / (float) words) * 100;
    float S = ((float) sentences / (float) words) * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;

    // check total based on the rounded float
    int total = round(index);
    if (total >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (total < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", total);
    }
}

int count_letters(string text)
{
    // count letters
    int letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isupper(text[i]) || islower(text[i]))
        {
            letters++;
        }
    }
    // return letters
    return letters;
}

int count_words(string text)
{
    // count words
    int words = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }
    // return words
    return words;
}

int count_sentences(string text)
{
    // count sentences
    int sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
    }
    // return sentences
    return sentences;
}