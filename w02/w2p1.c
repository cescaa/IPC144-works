/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P1)
Full Name  : Anna Francesca Dela Cruz
Student ID#: 123123150
Email      : afgdela-cruz@myseneca.ca
Section    : NJJ

Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
// #include <math.h> // library for math operations (e.g. ceilf())

int main()
{
    float smallShirt, mediumShirt, largeShirt;
    int numOfShirts;
    const double TAX = 0.13;
    const char patSize = 'S';

    printf("Set Shirt Prices\n");
    printf("================\n");

    // User input of prices
    printf("Enter the price for a SMALL shirt: $");
    scanf("%f", &smallShirt);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%f", &mediumShirt);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%f", &largeShirt);
    printf("\n");

    // Display prices
    printf("Shirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%.2f\n", smallShirt);
    printf("MEDIUM : $%.2f\n", mediumShirt);
    printf("LARGE  : $%.2f\n\n", largeShirt);

    printf("Patty's shirt size is \'%c\'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &numOfShirts); // User input of number of shirts
    printf("\n");

    // Cost Calculations
    float subTotalCents = ((smallShirt * numOfShirts) * 100) + 0.5; // convert to cents + round up halves
    int subTotal = subTotalCents;                                   // convert to integer
    int taxes = (TAX * subTotal) + 0.5;                             // round up half cents
    int total = subTotal + taxes;

    // Display costs
    printf("Patty's shopping cart...\n");
    printf("Contains : %d shirts\n", numOfShirts);
    printf("Sub-total: $%8.4lf\n", (subTotal) / (float)100); // convert to dollars & display totals to 4 decimal points
    printf("Taxes    : $%8.4lf\n", taxes / (float)100);
    printf("Total    : $%8.4lf\n", total / (float)100);

    return 0;
}