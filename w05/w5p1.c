/*/////////////////////////////////////////////////////////////////////////
							Workshop - #5 (P1)
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

#include <stdio.h>

int main()
{
	int flag = 1;
	const int JAN = 1, DEC = 12;
	int year, month;

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

			printf("Log starting date: %d-", year);

			// map month int to month name and print
			switch (month)
			{
			case 1:
				printf("JAN-01\n");
				break;
			case 2:
				printf("FEB-01\n");
				break;
			case 3:
				printf("MAR-01\n");
				break;
			case 4:
				printf("APR-01\n");
				break;
			case 5:
				printf("MAY-01\n");
				break;
			case 6:
				printf("JUN-01\n");
				break;
			case 7:
				printf("JUL-01\n");
				break;
			case 8:
				printf("AUG-01\n");
				break;
			case 9:
				printf("SEP-01\n");
				break;
			case 10:
				printf("OCT-01\n");
				break;
			case 11:
				printf("NOV-01\n");
				break;
			case 12:
				printf("DEC-01\n");
				break;
			}

			flag = 0;
		}

		/*
		// !!!! BUG: infinite loop if input is char; below does not fix it !!!!
		else
		{
			printf("ERROR: The year must be between 2012 and 2022 inclusive\n");
			printf("ERROR: Jan.(1) -Dec.(12)\n");
		}
		*/
	} while (flag == 1);

	return 0;
}