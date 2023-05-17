# TODO
from cs50 import get_string
# get text
text = get_string("Text: ")
textList = list(text)

countLetters = 0
countWords = 1
countSentences = 0

for i in range(len(textList)):
    # count letters
    if textList[i].isalpha():
        countLetters += 1
    # count words
    elif textList[i] == ' ':
        countWords += 1
    # count sentences
    elif textList[i] == '.' or textList[i] == '?' or textList[i] == '!':
        countSentences += 1

print(f'count letters: {countLetters}')
print(f'count words: {countWords}')
print(f'count words: {countSentences}')

# calculate total
L = (countLetters / countWords) * 100
S = (countSentences / countWords) * 100
index = 0.0588 * L - 0.296 * S - 15.8

total = round(index)
if total >= 16:
    print("Grade 16+")
elif total < 1:
    print("Before Grade 1")
else:
    print(f"Grade {total}")

# Congratulations! Today is your day. You're off to Great Places! You're off and away!