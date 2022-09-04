# getting user's input
text = str(input('Enter the text here: ').strip())

# lists of references for characters and sentence breakers, respectively
alphabet = (['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
            'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'])
punctuation = ['!', '.', '?']
# initiating counters
words = 1
letters = 0
sentences = 0

# looping through the text
for char in text:
    if char == " ":
        words += 1
    if char in punctuation:
        sentences += 1
    if char.lower() in alphabet:
        letters += 1

# Coleman-Liau index
index = (round((((0.0588 * 100 * letters) / words) - ((100 * 0.296 * sentences) / words)) - 15.8, 0))

# printing the equivalent result to the index found above
if index < 1:
    print('Before Grade 1')
elif index > 16:
    print('Grade 16+')
else:
    print(f'Grade {index}')