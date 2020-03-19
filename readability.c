#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

//Implement a program that computes the approximate grade level needed to comprehend some text

int main(void)
{
    string text = get_string("Text: ");
    int letters = 0;
    int words = 1;
    int sentences = 0;
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        //count the number of letters
        if ((text[i] >= 'a' || text[i] >= 'A') && (text[i] <= 'z' || text[i] <= 'Z'))
        {
            letters++;
        }
        //count the number of words
        else if (text[i] == ' ')
        {
            words++;
        }
        //count the number of sentences
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    //calculate L - the average number of letters per 100 words
    float L = letters / (float) words * 100;

    //calculate S - the average number of sentences per 100 words
    float S = sentences / (float) words * 100;

    //calculate the index using Coleman-Liau formula
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    //output according to index result
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
