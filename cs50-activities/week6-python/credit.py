# TODO
# inputing card's number
num = str(input('NUMBER: ').strip())
comp = len(num)
# checking whether the cards lenght is between the usual values of 13 and 16
if comp < 13 or comp > 16:
    print('INVALID')
    exit(0)

# conditinal definition of the starting range for card with a pair or odd number of digits
if len(num) % 2 == 0:
    ini1 = 0
    ini2 = 1
else:
    ini1 = 1
    ini2 = 0

# getting one of every two numbers from right to left starting from the second and adding them to a list
conta1 = []
for digit in reversed(range(ini1, comp, 2)):

    conta1.append((2*int(num[digit])))

# converting elements of the list to int to make the math and getting the total value of its digits
c = 0
for elemento in conta1:
    elemento = str(elemento)
    try:
        c = c + int(elemento[0]) + int(elemento[1])
    except:
        c = c + int(elemento[0])


# summing the remaining digits with the total calculated above
conta2 = []
for digit in reversed(range(ini2, comp, 2)):
    conta2.append(int(num[digit]))
final = c + sum(conta2)
valid = False
ck = str(final)
# checking whether the number complies with Luhn’s Algorithm or not
if ck[1] == '0':
    valid = True
else:
    print('INVALID')
    exit(0)
# printing the issuer's name based on the initial digits
# obs: a better solution would be creating a list of valid starting numbers for each card issuer, then look if the card being checked has its first digits matching one of that lists
if valid == True and (num.startswith('34') or num.startswith('37')):
    print('AMEX')
elif valid == True and (num.startswith('51') or num.startswith('52') or num.startswith('53') or num.startswith('54') or num.startswith('55')):
    print('MASTERCARD')
elif valid == True and num.startswith('4'):
    print('VISA')
else:
    print('INVALID')