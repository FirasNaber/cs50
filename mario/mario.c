#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height, i, j, space;
    do
    {
        height = get_int("Height: ");
    }

    while (height < 1 || height > 8);

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < height - i - 1; j++)
        {
            printf(" ");
        }

        for (j = 0; j <= i; j++)
        {
            printf("#");
        }

        printf("  ");
        for (j = 0; j <= i; j++)
        {
            printf("#");
        }

        printf("\n");
    }
}
