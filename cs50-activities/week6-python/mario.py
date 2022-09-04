# TODO
# Loop checking if the user is entering a valid number:
while True:
    try:
        n = str(input('Height: ').strip())
        entry = int(n)
        if (entry > 0) and (entry < 9):
            break
    except:
        pass

# Loops build the pyramid
for i in range(entry):
    for j in range(entry-i-1):
        print(" ", end='')
    for j in range(i+1):
        print('#', end='')
    print('  ', end='')
    for j in range(i+1):
        print('#', end='')
    print()