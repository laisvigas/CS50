# READABILITY: https://cs50.harvard.edu/x/2023/psets/6/readability/

from cs50 import get_string

text = get_string("Text: ")

# count the number of letters in the text
count_letters = 0
for c in text:
    if c.isalpha():
        count_letters += 1

# count the number of words in the text
count_words = len(text.split())

# count the number of sentences in the text
count_sentences = text.count(".") + text.count("!") + text.count("?")

# the average number of letters per 100 words in the text
L = count_letters / count_words * 100

# the average number of sentences per 100 words in the text
S = count_sentences / count_words * 100

# Coleman-Liau index
coleman_liau = 0.0588 * L - 0.296 * S - 15.8

# print the result
if coleman_liau >= 16:
    print("Grade 16+")
elif coleman_liau < 1:
    print("Before Grade 1")
else:
    print(f"Grade {round(coleman_liau)}")
