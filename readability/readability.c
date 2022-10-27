#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

float count_letters(string text);
float count_words(string text);
float count_sentences(string text);
float readability(string text);

int main()
{
    string text = get_string("Enter text: ");

    if (readability(text) < 1.0)
    {
        printf("Before Grade 1\n");
    }

    else if (readability(text) >= 16.0)
    {
        printf("Grade 16+\n");
    }

    else
    {
        printf("Grade %.f\n", readability(text));
    }
}

float count_letters(string text)
{
    int count = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (isalnum(text[i]))
        {
            count++;
        }
    }

    return count;
}

float count_words(string text)
{
    int count = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            count++;
        }
    }

    count++;

    return count;
}

float count_sentences(string text)
{
    int count = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }

    return count;
}

float readability(string text)
{
    float S = (count_letters(text) / count_words(text)) * 100;
    float L = (count_sentences(text) / count_words(text)) * 100;
    float index = 0.0588 * S - 0.296 * L - 15.8;

    return round(index);
}
