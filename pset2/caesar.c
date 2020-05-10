#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    //check if only two command-line arguments are provided  e.g. ./caesar 13)
    if (argc == 1 || argc > 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

//check that the command-line argument consists only of decimal digits
    for (int i = 0, length = strlen(argv[1]); i < length; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }

    }
// once all confirmed convert the string arg to an integer
    int arg = atoi(argv[1]);

//get plaintext
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");

//iterate over each alphabetical character of the plaintext and cipher it according to the command-line key provided

    for (int j = 0, length = strlen(plaintext); j < length; j++)
    {
//check if alphabetical character
        if (isalpha(plaintext[j]))
        {
//check if uppercase
            if (isupper(plaintext[j]))
            {

                char c = ((int) plaintext[j] + arg - 65) % 26 + 65;
                printf("%c", c);
            }
            else
            {
//else is lowercase
                char c = ((int) plaintext[j] + arg - 97) % 26 + 97;
                printf("%c", c);

            }

    }
//is not aplhabetical, therefore print unchanged
        else
        {
            printf("%c", plaintext[j]);
        }
    }

    printf("\n");
    return 0;
}
