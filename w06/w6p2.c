/*/////////////////////////////////////////////////////////////////////////
							Workshop - #6 (P2)
Full Name  : Anna Francesca Dela Cruz
Student ID#: 123123150
Email      : afgdela-cruz@myseneca.ca
Section    : NJJ

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

/*
Hi Cass,

As mentioned in Part 1, I posted my code on Stack Overflow:
https://stackoverflow.com/questions/75464775/beginner-in-c-cant-properly-printf-first-and-last-element-in-double-array/75464796#75464796

Also, Matrix won't let me submit unless I initialize outside of the () brackets first.
I also use an automatic formatter -- I think it's part of the C/C++ extension in VS Code -- that puts the "do" in do/while loops on a seperate line, above the opening { bracket. It won't let me put them together on the same line.
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX_ITEMS 10

#include <stdio.h>

// function prototypes
int printFinanceOpt(int finOpsYes);
int calcforecastYears(double totalCosts, double netIncome);
int calcforecastMons(double totalCosts, double netIncome);

int main()

{
	const double MIN_INCOME = 500, MAX_INCOME = 400000;
	int numOfItems, idxSpaces, flag = 1;
	double netIncome, totalCost;
	double itemCosts[MAX_ITEMS];
	int itemPriors[MAX_ITEMS];
	char itemFinOps[MAX_ITEMS], insertSpaces[4][5] = {" ", "  ", "   ", "    "};

	// menu-specific variables
	int menuSelct, menuPrior, finOpsYes = 0;
	double priorsCost;

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

	// Prompt wish list item details
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

	// display summary of wish list item details in chart
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
		totalCost += itemCosts[j];
	}

	printf("---- -------- -------- -----------\n");
	printf("                      $ %.2lf\n", totalCost);

	do ////////////////////////////// *** WISH LIST MENU + SUMMARY GENERATOR *** //////////////////////////////
	{
		do // prompt user to select menu option
		{
			printf("\nHow do you want to forecast your wish list?\n");
			printf(" 1. All items (no filter)\n");
			printf(" 2. By priority\n");
			printf(" 0. Quit/Exit\n");
			printf("Selection: ");
			scanf("%d", &menuSelct);

			if (!(menuSelct == 1 || menuSelct == 2 || menuSelct == 0))
			{
				printf("\nERROR: Invalid menu selection.\n");
			}
		} while (!(menuSelct == 1 || menuSelct == 2 || menuSelct == 0));

		////////////////// menu selection 1 //////////////////
		if (menuSelct == 1)
		{
			// check for financing options
			int z;
			for (z = 0; z < numOfItems; z++)
			{
				if (itemFinOps[z] == 'y')
				{
					finOpsYes = 1;
				}
			}

			// display summary
			printf("\n====================================================\n");
			printf("Filter:   All items\n");
			printf("Amount:   $%.2lf\n", totalCost);
			printf("Forecast: %d years, %d months\n", calcforecastYears(totalCost, netIncome), calcforecastMons(totalCost, netIncome));
			printFinanceOpt(finOpsYes);
			printf("====================================================\n");

			// reset value
			finOpsYes = 0;
		}

		////////////////// menu selection 2 //////////////////
		else if (menuSelct == 2)
		{
			// prompt for # of priority
			printf("\nWhat priority do you want to filter by? [1-3]: ");
			scanf("%d", &menuPrior);

			// add up item costs with same prority; store total in priorsCost
			int x;
			for (x = 0; x < numOfItems; x++)
			{
				if (itemPriors[x] == menuPrior)
				{
					priorsCost += itemCosts[x];
				}
			}

			// check financing options for priority items
			int z;
			for (z = 0; z < numOfItems; z++)
			{
				if (itemFinOps[z] == 'y')
				{
					if (itemPriors[z] == menuPrior)
					{
						finOpsYes = 1;
					}
				}
			}

			// display summary
			printf("\n====================================================\n");
			printf("Filter:   by priority (%d)\n", menuPrior);
			printf("Amount:   $%.2lf\n", priorsCost);
			printf("Forecast: %d years, %d months\n", calcforecastYears(priorsCost, netIncome), calcforecastMons(priorsCost, netIncome));
			printFinanceOpt(finOpsYes);
			printf("====================================================\n");

			// reset values
			finOpsYes = 0;
			priorsCost = 0.0;
		}

		////////////////// menu selection 0 //////////////////
		else // quit program
		{
			flag = 0;
		}
	} while (flag == 1);

	printf("\nBest of luck in all your future endeavours!\n");

	return 0;
}
//// END OF MAIN ////

int printFinanceOpt(int finOpsYes)
{
	if (finOpsYes == 1)
	{
		printf("NOTE: Financing options are available on some items.\n      You can likely reduce the estimated months.\n");
	}
	return 0;
}

// calculate forcasted years
int calcforecastYears(double totalCosts, double netIncome)
{
	double forecastDoub = totalCosts / netIncome;
	int forecastYrs = forecastDoub / 12;
	return forecastYrs;
}

// calculate forcasted months
int calcforecastMons(double totalCosts, double netIncome)
{
	double forecastDoub = totalCosts / netIncome;
	int forecastInt = (((forecastDoub - (int)forecastDoub) * 100) >= 5) ? (int)forecastDoub + 1 : forecastDoub;
	int forecastMons = forecastInt % 12;
	return forecastMons;
}