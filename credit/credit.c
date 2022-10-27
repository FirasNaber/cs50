#include <cs50.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int len(long n);
void checksum(long n);
long reverse(long n);

int main(void)
{
    // Prompt for input.
    long input = get_long("Number: ");
  
    checksum(input);
}

// Find the length of card number.
int len(long n)
{
    long temp = n;
    int count = 0;

    while (temp > 0)
    {
        temp /= 10;
        count++;
    }

    return count;
}

// Reverse card numbers
long reverse(long n)
{
    // From https://www.geeksforgeeks.org/write-a-program-to-reverse-digits-of-a-number/
    long rev_num = 0;

    while (n > 0)
    {
        rev_num = rev_num * 10 + n % 10;
        n /= 10;
    }
    return rev_num;
}

void checksum(long n)
{
    // Split card digits into array (reversed).
    int digits[len(n)];
    long temp = n;

    for (int i = 0; i < len(n); i++)
    {
        digits[i] = temp % 10;
        temp /= 10;
    }

    int sum = 0;
    for (int i = 1; i < len(n); i += 2)
    {
        // Multiply digits by 2.
        int curr = digits[i] * 2;
      
        // Add the sum of the digits of products.
        if (curr <= 9)
        {
            sum += curr;
        }

        else
        {
            for (int j = 0; j < 2; j++)
            {
                sum += curr % 10;
                curr /= 10;
            }
        }
    }

    // Add the rest of the numbers to the sum.
    for (int i = 0; i < len(n); i += 2)
    {
        sum += digits[i];
    }

    // Check for card length and starting digits.
    if (sum % 10 == 0)
    {
        // American Express checks.
        if ((reverse(n) % 100 == 43 || reverse(n) % 100 == 73) && len(n) == 15)
        {
            printf("AMEX\n");
        }

        // MasterCard checks.
        else if ((reverse(n) % 100 >= 15 && reverse(n) % 100 <= 55) && len(n) == 16)
        {
            printf("MASTERCARD\n");
        }

        // VISA checks.
        else if (reverse(n) % 10 == 4 && (len(n) == 13 || len(n) == 16))
        {
            printf("VISA\n");
        }

        // Invalid checks.
        else
        {
            printf("INVALID\n");
        }
    }

    else
    {
        printf("INVALID\n");
    }
}
