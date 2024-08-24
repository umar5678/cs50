#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

// players create words to score points, and the number of points is the sum of the point values of
// each letter in the word.

// alphabats and numbers

// program should prompt for input twice
// once for “Player 1” and once for “Player 2” to input their word
// depending on which player scores the most points, should either print “Player 1 wins!”, “Player 2
// wins!”, or “Tie!” Capital and small letter processed

//  take input from both palyers, store it in variables
//  calculate the sum of there crossponding digit
// before adding, equalize capital and small numbers
// compare the output number and show the result
const int points[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                      1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int computeScore(string word);

int main(void)
{
    string playerOneWord = get_string("Player 1: ");
    string playerTwoWord = get_string("Player 2: ");

    int scoreOne = computeScore(playerOneWord);
    int scoreTwo = computeScore(playerTwoWord);

    if (scoreOne > scoreTwo)
    {
        printf("Player 1 Wins!\n");
    }
    else if (scoreOne < scoreTwo)
    {
        printf("Player 2 Wins!\n");
    }
    else
    {
        printf("Tie");
    }
}

int computeScore(string word)
{
    int score = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        char letter = toupper(word[i]);
        if (letter >= 'A' && letter <= 'Z')
        {
            score += points[letter - 'A'];
        }
    }

    return score;
}
