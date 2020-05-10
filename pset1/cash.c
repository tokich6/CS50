#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
  float change;
   do
    {
       change = get_float("How much change are you owed? \n");
    }
    while(change < 0.00);
    int cents = round(change * 100);
    printf("Change owed: %.2i cents \n", cents);
    int coins = 0;
    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    int penny = 1;
    do
    {
      while (cents >= quarter)
     {
        cents -= quarter;
        coins++;
     }
    if (cents < quarter && cents >= dime)
    {
        cents -= dime;
        coins++;
    }
    if (cents < dime && cents >= nickel)
    {
        cents -= nickel;
        coins++;
    }
    if (cents < nickel && cents >= penny)
     {
        cents -= penny;
        coins++;
     }
    }
    while (cents > 0.00);

 printf("change left: %i \n", cents);
     printf("number of coints: %i \n", coins);
}
