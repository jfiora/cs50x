# TODO
while True:
    # get height and validate
    try:
        height = int(input("Height: "))
        if height > 0 and height < 9:
            break
    except ValueError:
        print("")

for i in range(1, height + 1):
    # left side
    leftSpaces = height - i
    for j in range(leftSpaces):
        print(" ", end="")

    for k in range(i):
        print("#", end="")
    # separate
    print("  ", end="")
    # right side
    for l in range(i):
        print("#", end="")
    # print new line
    print("")