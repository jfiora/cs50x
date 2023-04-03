#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // get height and validate
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    for (int i = 1; i <= height; i++)
    {
        // left side
        int left_spaces = height - i;
        for (int l = 0; l < left_spaces; l++)
        {
            printf(" ");
        }
        for (int j = 0; j < i; j++)
        {

            printf("#");
        }

        // print 2 spaces gap
        printf("  ");

        // right side
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }

        // print new line
        printf("\n");
    }
}