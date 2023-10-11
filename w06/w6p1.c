/*/////////////////////////////////////////////////////////////////////////
							Workshop - #6 (P1)
Full Name  : Anna Francesca Dela Cruz
Student ID#: 123123150
Email      : afgdela-cruz@myseneca.ca
Section    : NJJ

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

/************************************************************

Hi Cass!

I posted my code for Part 1 on Stack Overflow because I had trouble displaying the cost values in the table. Just letting you know it's my post and I didn't plagiarize! Thanks!

My Post: https://stackoverflow.com/questions/75464775/beginner-in-c-cant-properly-printf-first-and-last-element-in-double-array/75464796#75464796

*************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#define MAX_ITEMS 10

#include <stdio.h>

int main()
{
	const double MIN_INCOME = 500, MAX_INCOME = 400000;
	int numOfItems, idxSpaces;
	double netIncome, itemTotal;
	double itemCosts[MAX_ITEMS];
	int itemPriors[MAX_ITEMS];
	char itemFinOps[MAX_ITEMS], insertSpaces[4][5] = {" ", "  ", "   ", "    "};

	printf("+--------------------------+\n");
	printf("+   Wish List Forecaster   |\n");
	printf("+--------------------------+\n\n");

	do // Prompt for net monthly income
	{
		printf("Enter your monthly NET income: $");
		scanf("%lf", &netIncome);
		if (netIncome < MIN_INCOME)
		{
			printf("ERROR: You must have a consistent monthly income of at least $500.00\n\n");
		}
		else if (netIncome > MAX_INCOME)
		{
			printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n\n");
		}
	} while (!(netIncome >= MIN_INCOME && netIncome <= MAX_INCOME));

	printf("\n");

	do // Prompt for # of wish list items
	{
		printf("How many wish list items do you want to forecast?: ");
		scanf("%d", &numOfItems);

		if (!(numOfItems > 0 && numOfItems <= MAX_ITEMS))
		{
			printf("ERROR: List is restricted to between 1 and 10 items.\n");
		}

		printf("\n");
	} while (!(numOfItems > 0 && numOfItems <= MAX_ITEMS));

	// Store wish list item details
	int i; // matrix does not let me submit unless I initialize first
	for (i = 0; i < numOfItems; i++)
	{
		printf("Item-%d Details:\n", i + 1);

		do // prompt cost
		{
			printf("   Item cost: $");
			scanf("%lf", &itemCosts[i]);
			if (!(itemCosts[i] >= 100.0))
			{
				printf("      ERROR: Cost must be at least $100.00\n");
			}
		} while (!(itemCosts[i] >= 100.0));

		do // prompt priority
		{
			printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
			scanf("%d", &itemPriors[i]);
			if (!(itemPriors[i] >= 1 && itemPriors[i] <= 3))
			{
				printf("      ERROR: Value must be between 1 and 3\n");
			}
		} while (!(itemPriors[i] >= 1 && itemPriors[i] <= 3));

		do // prompt finance options
		{
			printf("   Does this item have financing options? [y/n]: ");
			scanf(" %c", &itemFinOps[i]);
			if (!(itemFinOps[i] == 'y' || itemFinOps[i] == 'n'))
			{
				printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
			}
		} while (!(itemFinOps[i] == 'y' || itemFinOps[i] == 'n'));

		printf("\n");
	}

	// display summary of item details in chart
	printf("Item Priority Financed        Cost\n");
	printf("---- -------- -------- -----------\n");

	// determine # of spaces for table
	int j; // matrix does not let me submit unless I initialize first
	for (j = 0; j < numOfItems; j++)
	{
		if (itemCosts[j] < 10000) // covers 4 digits
		{
			idxSpaces = 3;
		}
		else if (itemCosts[j] < 100000) // covers 5 digits
		{
			idxSpaces = 2;
		}
		else if (itemCosts[j] < 1000000) // covers 6 digits
		{
			idxSpaces = 1;
		}
		else
		{
			idxSpaces = 0; // covers > 6 digits
		}

		printf("  %d      %d        %c%s    %.2lf\n", j + 1, itemPriors[j], itemFinOps[j], insertSpaces[idxSpaces], itemCosts[j]);
		itemTotal += itemCosts[j];
	}

	printf("---- -------- -------- -----------\n");
	printf("                      $ %.2lf\n", itemTotal);
	printf("\nBest of luck in all your future endeavours!\n");

	return 0;
}