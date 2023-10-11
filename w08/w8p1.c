/*/////////////////////////////////////////////////////////////////////////
													Workshop - #8 (P1)
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

// System Libraries
#include <stdio.h>
// User Libraries
#include "w8p1.h"

int intPointer;
double doubPointer;

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int *intPointer)
{
	int intUserInput;
	do
	{
		scanf("%d", &intUserInput);
		if (intUserInput <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (intUserInput <= 0);

	if (intPointer != NULL)
	{

		*intPointer = intUserInput; // return by pointer argument (indirection operator)
		return *intPointer;
	}
	else
		return intUserInput; // return by return value
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double *doubPointer)
{
	double doubUserInput;
	do
	{
		scanf("%lf", &doubUserInput);
		if (doubUserInput <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (doubUserInput <= 0);

	if (doubPointer != NULL)
	{
		*doubPointer = doubUserInput; // return by pointer argument (indirection operator)
		return *doubPointer;
	}
	else
		return doubUserInput; // return by return value
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage()
{
	printf("Cat Food Cost Analysis\n======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\nNOTE: A 'serving' is %dg\n\n", MAX_PRODUCTS, SERV_GRAMS);
}

// 4. Get user input for the details of cat food product
void getCatFoodInfo(int intPointer, double doubPointer, struct CatFoodInfo *product, int counter)
{
	printf("Cat Food Product #%d\n--------------------\n", counter + 1);
	printf("SKU           : ");
	product->sku = getIntPositive(&intPointer);
	printf("PRICE         : $");
	product->price = getDoublePositive(&doubPointer);
	printf("WEIGHT (LBS)  : ");
	product->weightLbs = getDoublePositive(&doubPointer);
	printf("CALORIES/SERV.: ");
	product->cals = getIntPositive(&intPointer);
	printf("\n");
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(struct CatFoodInfo product)
{
	printf("%07d %10.2lf %10.1lf %8d\n", product.sku, product.price, product.weightLbs, product.cals);
}

// 7. Logic entry point
void start()
{

	struct CatFoodInfo products[MAX_PRODUCTS];
	openingMessage();

	int i;
	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		getCatFoodInfo(intPointer, doubPointer, &products[i], i);
	}
	displayCatFoodHeader();

	int j;
	for (j = 0; j < MAX_PRODUCTS; j++)
	{
		displayCatFoodData(products[j]);
	}
}
