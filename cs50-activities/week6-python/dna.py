import csv
import sys


def main():
    # TODO: Check for command-line usage
    if len(sys.argv) < 3:
        print('You are missing one or more command-line arguments!')
        exit(0)
    elif len(sys.argv) > 3:
        print("You're using more command-line arguments than expected. Please review your input!")
        exit(0)
    else:
        pass
    # TODO: Read database file into a variable
    # defining the database name and path
    csvpath = r'C:/Users/erick/Desktop/dna/databases/'
    fullcsv = sys.argv[1]
    pessoas = []
    # opening the database
    with open(fullcsv, 'r') as csvfile:
        # creating a database reader
        leitor = csv.reader(csvfile, delimiter=',')
        # iterating every row(person) and inside them (row[i]) iterating 9x to convert all values to int and assigning that to row[i]
        for row in leitor:
            for i in range(9):
                try:
                    row[i] = int(row[i])
                except:
                    pass
            # appending each row as a list to pessoas list (list of lists with head() included)
            pessoas.append(row)

    # TODO: Read DNA sequence file into a variable
    # defining the sequence name and path
    txtpath = r'C:/Users/erick/Desktop/dna/sequences/'
    fulltxt = sys.argv[2]
    # opening the sequence
    with open(fulltxt, 'r') as txtfile:
        # the linhatxt is just a huge dna sequence in one line/one element
        linhatxt = txtfile.read()
    # TODO: Find longest match of each STR in DNA sequence
    # resultsub is a list where each element is the longest subsequence in that sequence
    resultsub = [f'result {fulltxt}']
    for i, seq in enumerate(pessoas[0]):
        if seq != 'name':
            run_long = longest_match(linhatxt, pessoas[0][i])
            resultsub.append(run_long)

    # TODO: Check database for matching profiles
    novalista = []
    # if there's a match between 3 different subsequences, the person will be added to the list
    for item in pessoas:
        if item[i] == resultsub[i] and item[2] == resultsub[2] and item[3] == resultsub[3]:
            novalista.append(item)
    # showing the persons name or 'no match', case the list is empty
    if len(novalista) < 1:
        final = print('No match')
    else:
        final = print(novalista[0][0])
    return final


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()