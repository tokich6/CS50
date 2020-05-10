#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do 
    { 
      height = get_int("Please provide a number between 1 and 8: \n");
    } 
    while (height < 1 || height > 8);
    for(int line=0; line < height; line++) 
    { 
        for(int i=0; i<height; i++) { 
            if(i+line < height-1) {
                printf(" ");
            } else {
                printf("#");
            }
          }
         printf("\n"); 
    }       
}

