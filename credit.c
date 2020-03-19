#include <cs50.h>
#include <stdio.h>

int main(void)
{  
    //Declare and initialize variables
    long cardNumber, xadd, x2;
    int addSum, sum, x2products;

    //ask for credit card number
    do 
    {
        cardNumber = get_long("Please type your card number: \n");
        //printf("Number: %li \n", cardNumber);
    }
    while (cardNumber < 0);

    //sum every other digit starting with the last
    for(xadd = cardNumber, addSum=0; xadd > 0; xadd /= 100)
    {
        addSum += xadd % 10;
    }
    //printf("addSum is: %i\n", addSum);

    // double every other digit starting w/ 2nd to last
    // then sum the individual digits of these products
    for(x2 = cardNumber / 10, x2products = 0; x2 > 0; x2 /= 100)
    {
        if (2 * (x2 % 10) > 9)
        {
            x2products += (2 * (x2 % 10)) / 10;
            x2products += (2 * (x2 % 10)) % 10;
        }
        else 
        x2products += 2 * (x2 % 10);
    }
    //printf("The total of every other digit mupliplied by 2, starting from the second to last is: %i \n", x2products);

    //calculate the sum of the 2 totals:
    sum = addSum + x2products;

    //determine whether the cardNumber has a valid number of digits and the card type
    if(sum % 10 == 0) 
    {
        if((cardNumber >= 340000000000000 && cardNumber < 350000000000000) || (cardNumber >=      370000000000000 && cardNumber < 380000000000000))
        printf("AMEX\n");
        else if(cardNumber >= 5100000000000000 && cardNumber < 5600000000000000)
        printf("MASTERCARD\n");
        else if((cardNumber >= 4000000000000 && cardNumber < 5000000000000) || (cardNumber >= 4000000000000000 && cardNumber < 5000000000000000))
        printf("VISA\n");
        else 
        printf("INVALID\n");
    }
    else 
    printf("INVALID\n");
}
