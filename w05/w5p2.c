/*/////////////////////////////////////////////////////////////////////////
							Workshop - #5 (P2)
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
#define MIN_YEAR 2012
#define MAX_YEAR 2022
#define LOG_DAYS 3

#include <stdio.h>

double promptUserMrng(double mrngVal, double ratingMin, double ratingMax);
double promptUserEvng(double evngVal, double ratingMin, double ratingMax);

int main()
{
	int flag = 1;
	const int JAN = 1, DEC = 12;
	int year, month;
	double ratingMin = 0.0, ratingMax = 5.0, mrngVal, evngVal, mrngSum, evngSum;

	printf("General Well-being Log\n");
	printf("======================\n");

	// prompt for year + month until valid
	do
	{
		printf("Set the year and month for the well-being log (YYYY MM): ");
		scanf("%d %d", &year, &month);

		if ((year > MAX_YEAR || year < MIN_YEAR) && (month >= JAN && month <= DEC))
		{
			printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
		}
		else if ((year <= MAX_YEAR && year >= MIN_YEAR) && !(month >= JAN && month <= DEC))
		{
			printf("   ERROR: Jan.(1) - Dec.(12)\n");
		}
		else if ((year > MAX_YEAR || year < MIN_YEAR) && !(month >= JAN && month <= DEC))
		{
			printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
			printf("   ERROR: Jan.(1) - Dec.(12)\n");
		}
		else if ((year <= MAX_YEAR && year >= MIN_YEAR) && (month >= JAN && month <= DEC))
		{
			printf("\n*** Log date set! ***\n\n");

			flag = 0;
		}
	} while (flag == 1);

	// FOR LOOP
	int i; // need to declare first or matrix will not accept
	for (i = 0; i < LOG_DAYS; i++)
	{
		// print year
		printf("%d-", year);

		// map month int to month name and print
		switch (month)
		{
		case 1:
			printf("JAN-");
			break;
		case 2:
			printf("FEB-");
			break;
		case 3:
			printf("MAR-");
			break;
		case 4:
			printf("APR-");
			break;
		case 5:
			printf("MAY-");
			break;
		case 6:
			printf("JUN-");
			break;
		case 7:
			printf("JUL-");
			break;
		case 8:
			printf("AUG-");
			break;
		case 9:
			printf("SEP-");
			break;
		case 10:
			printf("OCT-");
			break;
		case 11:
			printf("NOV-");
			break;
		case 12:
			printf("DEC-");
			break;
		}

		// prompt and print data for any day from 1 - 28
		if (i >= 0 && i <= 8)
		{
			printf("0%d\n", i + 1);
			mrngVal = promptUserMrng(mrngVal, ratingMin, ratingMax);
			evngVal = promptUserEvng(evngVal, ratingMin, ratingMax);
			mrngSum += mrngVal;
			evngSum += evngVal;
			printf("\n");
		}
		else if (i >= 9 && i <= 27)
		{
			printf("%d\n", i + 1);
			mrngVal = promptUserMrng(mrngVal, ratingMin, ratingMax);
			evngVal = promptUserEvng(evngVal, ratingMin, ratingMax);
			mrngSum += mrngVal;
			evngSum += evngVal;
			printf("\n");
		}
		else
		{
			printf("\n");
			mrngVal = promptUserMrng(mrngVal, ratingMin, ratingMax);
			evngVal = promptUserEvng(evngVal, ratingMin, ratingMax);
			mrngSum += mrngVal;
			evngSum += evngVal;
			printf("\n");
		}
	}

	printf("Summary\n");
	printf("=======\n");
	printf("Morning total rating: %0.3lf\n", mrngSum);
	printf("Evening total rating:  %0.3lf\n", evngSum);
	printf("----------------------------\n");
	printf("Overall total rating: %0.3lf\n\n", mrngSum + evngSum);

	printf("Average morning rating:  %0.1lf\n", mrngSum / LOG_DAYS);
	printf("Average evening rating:  %0.1lf\n", evngSum / LOG_DAYS);
	printf("----------------------------\n");
	printf("Average overall rating:  %0.1lf\n", (mrngSum + evngSum) / LOG_DAYS / 2);

	return 0;
}

// prompt user for MORNING value until valid
double promptUserMrng(double mrngVal, double ratingMin, double ratingMax)
{
	do
	{
		printf("   Morning rating (0.0-5.0): ");
		scanf("%lf", &mrngVal);
		if (!(mrngVal >= ratingMin && mrngVal <= ratingMax))
		{
			printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
		}
	} while (!(mrngVal >= ratingMin && mrngVal <= ratingMax));

	return mrngVal;
}

// prompt user for EVENING value until valid
double promptUserEvng(double evngVal, double ratingMin, double ratingMax)
{
	do
	{
		printf("   Evening rating (0.0-5.0): ");
		scanf("%lf", &evngVal);
		if (!(evngVal >= ratingMin && evngVal <= ratingMax))
		{
			printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
		}
	} while (!(evngVal >= ratingMin && evngVal <= ratingMax));

	return evngVal;
}