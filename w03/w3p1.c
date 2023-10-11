/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P1)
Full Name  : Anna Francesca Dela Cruz
Student ID#: 123123150
Email      : afgdela-cruz@myseneca.ca
Section    : NJJ

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#include <stdio.h>

int main(void)
{
    // You must use this variable in #3 data analysis section!
    const double testValue = 330.99;

    const int proId1 = 111, proId2 = 222, proId3 = 111;             // product ID
    const double price1 = 111.49, price2 = 222.99, price3 = 334.49; // price
    const char tax1 = 'Y', tax2 = 'N', tax3 = 'N';
    const double priceAvg = (price1 + price2 + price3) / 3; // tax

    printf("Product Information\n");
    printf("===================\n");

    printf("Product-1 (ID:%d)\n", proId1);
    printf("  Taxed: %c\n", tax1);
    printf("  Price: $%8.4lf\n\n", price1);

    printf("Product-2 (ID:%d)\n", proId2);
    printf("  Taxed: %c\n", tax2);
    printf("  Price: $%8.4lf\n\n", price2);

    printf("Product-3 (ID:%d)\n", proId3);
    printf("  Taxed: %c\n", tax3);
    printf("  Price: $%8.4lf\n\n", price3);

    printf("The average of all prices is: $%8.4lf\n\n", priceAvg);

    printf("About Relational and Logical Expressions!\n");
    printf("========================================\n");
    printf("1. These expressions evaluate to TRUE or FALSE\n");
    printf("2. FALSE: is always represented by integer value 0\n");
    printf("3. TRUE : is represented by any integer value other than 0\n\n");

    printf("Some Data Analysis...\n");
    printf("=====================\n");
    printf("1. Is product 1 taxable? -> %d\n\n", tax1 == 'Y');
    printf("2. Are products 2 and 3 both NOT taxable (N)? -> %d\n\n", tax2 != 'Y' && tax3 != 'Y');
    printf("3. Is product 3 less than testValue ($%.2lf)? -> %d\n\n", testValue, price3 < testValue);
    printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n\n", price3 > price1 + price2);
    printf("5. Is the price of product 1 equal to or more than the price difference\n   of product 3 LESS product 2? ->  %d (price difference: $%.2lf)\n\n", price1 >= (price3 - price2), price3 - price2);
    printf("6. Is the price of product 2 equal to or more than the average price? -> %d\n\n", price2 >= priceAvg);
    printf("7. Based on product ID, product 1 is unique -> %d\n\n", proId1 == proId2 && proId1 == proId3);
    printf("8. Based on product ID, product 2 is unique -> %d\n\n", proId2 != proId1 && proId2 != proId3);
    printf("9. Based on product ID, product 3 is unique -> %d\n", proId3 == proId2 && proId3 == proId1);

    return 0;
}