#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int validate_key(const char *key);
void substitute(const char *key, const char *plaintext, char *ciphertext);

int main(int argc, string argv[])
{
    // declare usage
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // setting key
    char key[27] = "";
    strncpy(key, argv[1], 26);
    key[26] = '\0';

    // validate key
    if (validate_key(key))
    {
        return 1;
    }

    string plaintext = get_string("plaintext: ");

    char ciphertext[strlen(plaintext) + 1];

    substitute(key, plaintext, ciphertext);

    printf("ciphertext: %s\n", ciphertext);

    return 0;
}

// Function to validate the key
int validate_key(const char *key)
{
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    int count[26] = {0};
    for (int i = 0; i < 26; i++)
    {
        char c = tolower(key[i]);

        if (c < 'a' || c > 'z')
        {
            printf("Key must contain only alphabetic characters.\n");
            return 1;
        }

        count[c - 'a']++;

        if (count[c - 'a'] > 1)
        {
            printf("Key must contain each letter exactly once.\n");
            return 1;
        }
    }
    return 0;
}

// Function for substitution

void substitute(const char *key, const char *plaintext, char *ciphertext)
{

    for (int i = 0; i < strlen(plaintext); i++)
    {
        char c = plaintext[i];
        if (isalpha(c))
        {
            if (isupper(c))
            {
                c = toupper(key[tolower(c) - 'a']);
            }
            else
            {
                c = tolower(key[c - 'a']);
            }
        }
        ciphertext[i] = c;
    }

    ciphertext[strlen(plaintext)] = '\0';
}
