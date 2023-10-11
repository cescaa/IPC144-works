/*/////////////////////////////////////////////////////////////////////////
							Workshop - #4 (P2)
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

int main()
{
	int flag = 1;
	int flagAnsw; // var to continue shopping or not

	do
	{
		char fruitNames[][10] = {"APPLES", "ORANGES", "PEARS", "TOMATOES", "CABBAGES"};
		char tooManyFruits[][11] = {"APPLE(S)", "ORANGE(S)", "PEAR(S)", "TOMATO(ES)", "CABBAGE(S)"};

		// unsure if we're allowed to use ctype.h
		char lowerCaseFruits[][10] = {"apples", "oranges", "pears", "tomatoes", "cabbages"};
		int fruitQty[5];
		int fruitPicked;

		printf("Grocery Shopping\n================\n");

		// ask user quantity of each fruit
		// !!!!! BUG: infinite loop when input is char !!!!!
		int i; // need C99; produces error if I don't declare beforehand
		for (i = 0; i < 5; i++)
		{
			do
			{
				printf("How many %s do you need? : ", fruitNames[i]);
				scanf("%d", &fruitQty[i]);
				if (fruitQty[i] < 0)
				{
					printf("ERROR: Value must be 0 or more.\n");
				}
				else if (fruitQty[i] >= 0)
				{
					printf("\n");
				}
			} while (fruitQty[i] < 0);
		}

		printf("--------------------------\nTime to pick the products!\n--------------------------\n\n");

		// compare needed quantity VS picked fruit
		int j; // need C99; produces error if I don't declare beforehand
		for (j = 0; j < 5; j++)
		{
			int fruitCart = fruitQty[j]; // needed to calc remaining qty to be picked

			if (fruitQty[j] > 0)
			{
				do
				{
					printf("Pick some %s... how many did you pick? : ", fruitNames[j]);
					scanf("%d", &fruitPicked);

					if (fruitPicked <= 0)
					{
						printf("ERROR: You must pick at least 1!\n");
					}
					else if (fruitPicked > fruitQty[j])
					{
						printf("You picked too many... only %d more %s are needed.\n", fruitCart, tooManyFruits[j]);
					}
					else if (fruitPicked > 0 && fruitPicked < fruitQty[j])
					{
						fruitCart = fruitCart - fruitPicked; // subtract from fruitCart # of picked fruit if < than needed qty
						if (fruitCart != 0)
						{
							printf("Looks like we still need some %s...\n", fruitNames[j]);
						}
						else
						{
							// fruitCart = 0; // note to self: check if necessary
							printf("Great, that's the %s done!\n\n", lowerCaseFruits[j]);
						}
					}
					else if (fruitPicked == fruitQty[j] || fruitCart == 0)
					{
						fruitCart = 0;
						printf("Great, that's the %s done!\n\n", lowerCaseFruits[j]);
					}
				} while (fruitPicked != fruitQty[j] && fruitCart != 0);
			}
		}

		printf("All the items are picked!\n\n");
		printf("Do another shopping? (0=NO): ");
		scanf("%d", &flagAnsw);
		printf("\n");

		flag = (flagAnsw == 1) ? 1 : 0; // quit depending on flagAnsw
	} while (flag == 1);

	printf("Your tasks are done for today - enjoy your free time!\n");

	return 0;
}