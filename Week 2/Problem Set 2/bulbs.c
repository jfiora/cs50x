#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // TODO
    string input = get_string("Message: ");

    for (int i = 0; i < strlen(input); i++)
    {
        char c = input[i];
        int value = (int) c;
        int bits[BITS_IN_BYTE];

        // convert into binary
        for (int j = BITS_IN_BYTE - 1; j >= 0; j--)
        {
            bits[j] = value & 1;
            value >>= 1;
        }

        // print the result
        for (int j = 0; j < 8; j++)
        {
            print_bulb(bits[j]);
        }
        // backslash + n for new line after bulbs
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}