#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

// declareing the three functions who counts the letters, words and sentences

int count_letters(string text);

int count_words(string text);

int count_sentences(string text);

int index;

string indexf;


int main(void)
{
// asks for the user's input
    string text = get_string("Place the text here: ");
// print that input
    printf("Your input: %s\n", text);

    int nletters = count_letters(text);

    int nwords = count_words(text);

    int nsentences = count_sentences(text);
    // parameters for the index calculation
    float L = 100 * (nletters / (float) nwords);

    float S = 100 * (nsentences / (float) nwords);
// the Coleman-Liau index
    index = round(((0.0588 * L) - (0.296 * S) - 15.8));
// code responsible for printing some details about the input
    printf("The text consists of %i letters, %i word(s), and %i sentence(s).\n", nletters, nwords, nsentences);

    // IF used to determine what index information should be printed after the information above.
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

}

// lines of code to determine the number of letters
int count_letters(string text)
{
    int letters = 0;
    int i = 0;
    int len = strlen(text);

    for (i = 0, len = strlen(text); i < len; i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letters++;
        }
    }
    return letters;
}

// lines of code to determine the number of words
int count_words(string text)
{
    int words = 1;
    int i = 0;
    int n = strlen(text);

    for (i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ')
        {
            words += 1;
        }
    }

    return words;

}

// lines of code to determine the number of sentences
int count_sentences(string text)
{
    int sentences = 0;
    int i = 0;
    int sch = strlen(text);

    for (i = 0, sch = strlen(text); i < strlen(text); i++)
    {
        if ((text[i] == '.') || (text[i] == '!') || (text[i] == '?'))
        {
            sentences++;
        }
    }
    if (sentences <= 0)
    {
        return sentences + 1;
    }
    else
    {
        return sentences;
    }

}

