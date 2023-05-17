# TODO
def check_sum(credit_card):
    digit = 0
    sum1 = 0
    sum2 = 0
    count = 0

    # split the credit card number into digits
    while credit_card > 0:
        digit = credit_card % 10
        credit_card //= 10

        if count % 2 != 0:
            double_value = digit * 2
            if double_value > 9:
                dozen = double_value // 10
                unit = double_value % 10
                sum1 += dozen + unit
            else:
                sum1 += double_value
        else:
            sum2 += digit

        count += 1

    total = sum1 + sum2

    # check if the last digit is 0 to complete the validation of the credit card
    return total % 10 == 0


# prompt for input
credit_card = int(input("Number: "))

# calculate checksum
validate = check_sum(credit_card)

# check for card length and starting digits
credit_card_str = str(credit_card)
first_digits = int(credit_card_str[:2])
count = len(credit_card_str)

# print result
if (first_digits == 34 or first_digits == 37) and count == 15 and validate:
    print("AMEX")
elif (first_digits > 50 and first_digits < 56) and count == 16 and validate:
    print("MASTERCARD")
elif (first_digits > 39 and first_digits < 50) and (count == 16 or count == 13) and validate:
    print("VISA")
else:
    print("INVALID")