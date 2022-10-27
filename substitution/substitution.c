#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int ciphertext(string key, char *x, char *y);
char *upper_alpha_array(void);
char *lower_alpha_array(void);

int main(int argc, string argv[])
{
    char *upper_ordered_chars = upper_alpha_array();
    char *lower_ordered_chars = lower_alpha_array();
    string key = argv[1];

    if (argc == 2)
    {
        int n = strlen(key);

        if (n != 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }

        for (int i = 0; i < n; i++)
        {
            if (!isalpha(key[i]))
            {
                printf("Key must only contain alphabetic characters.\n");
                return 1;
            }

            key[i] = toupper(key[i]);

            for (int j = i + 1; j < n; j++)
            {
                if (toupper(key[j]) == toupper(key[i]))
                {
                    printf("Key must only contain one of each alphabetic character.\n");
                    return 1;
                }
            }
        }

        ciphertext(key, upper_ordered_chars, lower_ordered_chars);
    }

    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}

int ciphertext(string key, char *x, char *y)
{
    string plaintext = get_string("plaintext: ");
    int n = strlen(plaintext);

    for (int i = 0; i < n; i++)
    {
        int index = 0;

        for (int j = 0; j < strlen(x); j++)
        {
            if (isupper(plaintext[i]))
            {
                if (plaintext[i] == x[j])
                {
                    plaintext[i] = key[index];
                    break;
                }

                index++;
            }

            else
            {
                if (plaintext[i] == y[j])
                {
                    plaintext[i] = tolower(key[index]);
                    break;
                }

                index++;
            }
        }
    }

    printf("ciphertext: %s\n", plaintext);
    return 0;
}

char *upper_alpha_array()
{
    int ascii = 65;
    static char arr[26];

    for (int i = 0; i < 26; i++)
    {
        arr[i] = ascii;
        ascii++;
    }

    return arr;
}

char *lower_alpha_array()
{
    int ascii = 97;
    static char arr[26];

    for (int i = 0; i < 26; i++)
    {
        arr[i] = ascii;
        ascii++;
    }

    return arr;
}
