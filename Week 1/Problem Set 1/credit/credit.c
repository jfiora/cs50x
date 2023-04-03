#include <cs50.h>
#include <stdio.h>

bool check_sum(long);

int main(void)
{
    // prompt for input
    long credit_card = get_long("Number: ");

    // calculate checksum
    bool validate = check_sum(credit_card);

    //check for card lenght and starting digits
    int count = 0;
    long aux = credit_card;
    while (aux != 0)
    {
        aux = aux / 10;
        count++;
    }

    long first_digits = credit_card;
    while (first_digits >= 100)
    {
        first_digits /= 10;
    }

    //print result
    if ((first_digits == 34 || first_digits == 37) && count == 15 && validate)
    {
        printf("AMEX\n");
    }
    else if ((first_digits > 50 && first_digits < 56) && count == 16 && validate)
    {
        printf("MASTERCARD\n");
    }
    else if ((first_digits > 39 && first_digits < 50) && (count == 16 || count == 13) && validate)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

bool check_sum(long credit_card)
{
    int digit = 0;
    int sum1 = 0;
    int sum2 = 0;
    int count = 0;
    // split the credit card number into digits
    while (credit_card > 0)
    {
        digit = credit_card % 10;
        credit_card /= 10;
        if (count % 2 != 0)
        {
            int double_value = digit * 2;
            if (double_value > 9)
            {
                // separate the value if it pass the 2 digits and add to the sum
                int dozen = double_value / 10;
                int unit = double_value % 10;
                sum1 = sum1 + dozen + unit;
            }
            else
            {
                sum1 = sum1 + double_value;
            }
        }
        else
        {
            sum2 = sum2 + digit;
        }
        // use a count to simulate the index of an array
        count++;
    }

    int total = sum1 + sum2;

    // check if value last digit is a 0 to complete the validation of the credit card
    return total % 10 == 0;
}