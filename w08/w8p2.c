/*/////////////////////////////////////////////////////////////////////////
													Workshop - #8 (P2)
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
#include "w8p2.h"

int intPointer;
double doubPointer;
int cheapestIdx; // index of cheapest cat food

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
		return intUserInput;
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
		return doubUserInput;
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
// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double *lbsPointer, double *KgResult)
{
	if (KgResult != NULL)
	{
		double result = *lbsPointer / LBS_TO_KG;
		*KgResult = result;
		return *KgResult; // return by pointer argument (indirection operator)
	}
	else
	{
		return *lbsPointer / LBS_TO_KG; // return by return value
	}
}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double *lbsPointer, int *GResult)
{
	if (GResult != NULL)
	{
		double convResult = *GResult;
		int result = convertLbsKg(lbsPointer, &convResult) * 1000;
		*GResult = result;
		return *GResult;
	}
	else
	{
		double result = convertLbsKg(lbsPointer, NULL) * 1000;
		return result;
	}
}

// 10. convert lbs: kg and g
void convertLbs(const double *lbsPointer, double *KgResult, int *GResult)
{
	*KgResult = convertLbsKg(lbsPointer, KgResult);
	*GResult = convertLbsG(lbsPointer, GResult);
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int serv, const int totalGrams, double *numOfServ)
{
	if (numOfServ != NULL)
	{
		*numOfServ = totalGrams / serv;
		return *numOfServ;
	}
	else
	{
		return (double)totalGrams / serv;
	}
}

// 12. calculate: cost per serving
double calculateCostPerServing(const double *price, const double *numOfServ, double *costPerServ)
{
	if (costPerServ != NULL)
	{
		*costPerServ = *price / *numOfServ;
		return *costPerServ;
	}
	else
	{
		return *price / *numOfServ;
	}
}

// 13. calculate: cost per calorie
double calculateCostPerCal(const double *price, const double *calories, double *costPerCalorie)
{
	if (costPerCalorie != NULL)
	{
		*costPerCalorie = *price / *calories;
		return *costPerCalorie;
	}
	else
	{
		return *price / *calories;
	}
}

struct ReportData calculateReportData(const struct CatFoodInfo product)
{
	struct ReportData report;
	report.sku = product.sku;
	report.price = product.price;
	report.cals = product.cals;
	report.weightLbs = product.weightLbs;
	report.weightKg = convertLbsKg(&product.weightLbs, NULL);
	report.weightGr = convertLbsG(&product.weightLbs, NULL);
	report.servs = calculateServings(SERV_GRAMS, report.weightGr, NULL);
	report.costPerServ = calculateCostPerServing(&product.price, &report.servs, NULL);
	const double doubCals = product.cals;
	report.calsPerServ = calculateCostPerCal(&report.costPerServ, &doubCals, NULL);

	return report;
}
// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("\nAnalysis Report (Note: Serving = %dg)\n", SERV_GRAMS);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData report, const int cheapest, int cheapIdx)
{
	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", report.sku, report.price, report.weightLbs, report.weightKg, report.weightGr, report.cals, report.servs, report.costPerServ, report.calsPerServ);

	if (cheapest == 0)
	{
		printf(" ***\n");
		cheapestIdx = cheapIdx;
	}
	else
	{
		printf("\n");
	}
}

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo product)
{
	printf("\nFinal Analysis\n--------------\nBased on the comparison data, the PURRR-fect economical option is:\nSKU:%d Price: $%.2lf\n\nHappy shopping!", product.sku, product.price);
}

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start()
{

	struct CatFoodInfo products[MAX_PRODUCTS]; // array of cat food product struct
	struct ReportData report[MAX_PRODUCTS];		 // array of report struct
	openingMessage();													 // display message

	int i;
	for (i = 0; i < MAX_PRODUCTS; i++) // loop for all products
	{
		getCatFoodInfo(intPointer, doubPointer, &products[i], i); // get user inputs for cat product
		report[i] = calculateReportData(products[i]);							// calculate report based on cat ptoduct
	}
	displayCatFoodHeader();

	int j;
	for (j = 0; j < MAX_PRODUCTS; j++)
	{
		displayCatFoodData(products[j]);
	}
	displayReportHeader();

	int z;
	for (z = 0; z < MAX_PRODUCTS; z++)
	{
		int cheapest = report[z].costPerServ;
		displayReportData(report[z], cheapest, z);
	}
	printf("\nFinal Analysis\n--------------\nBased on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%.2lf\n\n", report[cheapestIdx].sku, report[cheapestIdx].price);
	printf("Happy shopping!\n");
}
