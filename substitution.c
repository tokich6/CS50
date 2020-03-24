#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int uniqueChar(string str);


int main(int argc, string argv[])
{
//check if only two command-line arguments are provided  e.g. ./substitution a)
    if (argc != 2)
    {
        printf("Please provide a key\n");
        return 1;
    }
//validate the key
    int length = strlen(argv[1]);
    int alphabet = 26;

    for (int i = 0; i < length; i++)
    {
        if (((int)length) != alphabet)
        {
            printf("Key must be 26 charachters long\n");
            return 1;
        }
        else if (!isalpha(argv[1][i]))
        {
            printf("Key must contain only alphabetic characters\n");
            return 1;
        }
    }
//validate all characters as unique, see function below
    if (uniqueChar(argv[1]))
    {
        return 1;
    }

//prompt user for text
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");

//iterate over each alphabetical character of the plaintext and cipher it according to the command-line key provided

  for (int x = 0, text = strlen(plaintext); x < text; x++)
  {
      for (int y = 0; y < 26; y++)
      {
          if (plaintext[x] == 'a' + y)
          {
             if (islower(argv[1][y]))
             {
                 printf("%c", argv[1][y]);
             }
             else
             {
                 char cap = argv[1][y] + 32;
                 printf("%c", cap);
             }
          }
          else if (plaintext[x] == 'A' + y)
          {
             if (islower(argv[1][y]))
             {
                 char low = argv[1][y] -32;
                 printf("%c", low);
             }
             else
             {
                 printf("%c", argv[1][y]);
             }
           }
       }

       if (!isalpha(plaintext[x]))
       {
           printf("%c", plaintext[x]);
       }
    }

    printf("\n");
    return 0;
}



int uniqueChar(string str)
{
    for (int k = 0, length = strlen(str); k < length - 1; k++)
    {
        for (int j = k + 1; j < length; j++)
        {
            if (str[k] == str[j])
            {
                printf("All characters must be unique\n");
                return 1;
            }
        }
    }
    printf("%s\n", str);
    return 0;
}
