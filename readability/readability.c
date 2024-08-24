#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Prompt the user for some text

// Count the number of letters, words, and sentences in the text

// Compute the Coleman-Liau index

// index = 0.0588 * L - 0.296 * S - 15.8

// where L is the average number of letters per 100 words in the text, and S is the average number
// of sentences per 100 words in the text.

// Print the grade level

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
float avg_letters_per_100_words(int letters, int words);
float avg_sentences_per_100_words(int sentences, int words);

int main(void)
{
    int index = 0;
    string text = get_string("Text: ");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    float L = avg_letters_per_100_words(letters, words);
    float S = avg_sentences_per_100_words(sentences, words);

    index = 0.0588 * L - 0.296 * S - 15.8;

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

// calculate average letters per 100 words

float avg_letters_per_100_words(int letters, int words)
{
    return ((float) letters / (float) words) * 100;
}

// calculate average sentences per 100 words

float avg_sentences_per_100_words(int sentences, int words)
{
    return ((float) sentences / (float) words) * 100;
}

// Count number of letters

int count_letters(string text)
{
    int letters = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] != ' ' && text[i] != '.' && text[i] != '!')
        {
            letters++;
        }
    }
    return letters;
}

// Count number of words

int count_words(string text)
{
    // we can remove words and return spaces + 1 directly, or initialize spaces = 1 and return it
    int words = 0;
    int spaces = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == ' ')
        {
            spaces++;
        }
    }
    words = spaces + 1;
    return words;
}

// Count number of sentences

int count_sentences(string text)
{
    int sentences = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
    }
    return sentences;
}
