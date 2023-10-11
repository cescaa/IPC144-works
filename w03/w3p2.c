/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P2)
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
  const double GRAMS_IN_LBS = 453.5924;

  // product data
  char light, medium, rich, yesCream, noCream;
  int w250, w500, w1000; // weight

  // user inputs
  char typeInput, creamInput;
  int servInput;

  printf("Take a Break - Coffee Shop\n");
  printf("==========================\n\n");

  printf("Enter the coffee product information being sold today...\n\n");

  printf("COFFEE-1...\n");
  printf("Type ([L]ight,[M]edium,[R]ich): ");
  scanf(" %c", &light);
  printf("Bag weight (g): ");
  scanf("%d", &w250);
  printf("Best served with cream ([Y]es,[N]o): ");
  scanf(" %c", &yesCream);

  printf("\nCOFFEE-2...\n");
  printf("Type ([L]ight,[M]edium,[R]ich): ");
  scanf(" %c", &rich);
  printf("Bag weight (g): ");
  scanf("%d", &w500);
  printf("Best served with cream ([Y]es,[N]o): ");
  scanf(" %c", &noCream);

  printf("\nCOFFEE-3...\n");
  printf("Type ([L]ight,[M]edium,[R]ich): ");
  scanf(" %c", &medium);
  printf("Bag weight (g): ");
  scanf("%d", &w1000);
  printf("Best served with cream ([Y]es,[N]o): ");
  scanf(" %c", &noCream);

  printf("\n---+------------------------+---------------+-------+\n");
  printf("   |    Coffee              |   Packaged    | Best  |\n");
  printf("   |     Type               |  Bag Weight   | Served|\n");
  printf("   +------------------------+---------------+ With  |\n");
  printf("ID | Light | Medium | Rich  |  (G) | Lbs    | Cream |\n");
  printf("---+------------------------+---------------+-------|\n");

  printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", light == 'l' || light == 'L', light == 'm' || light == 'M', light == 'r' || light == 'R', w250, w250 / GRAMS_IN_LBS, yesCream == 'y' || yesCream == 'Y');
  printf(" 2 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", rich == 'l' || rich == 'L', rich == 'm' || rich == 'M', rich == 'r' || rich == 'R', w500, w500 / GRAMS_IN_LBS, noCream == 'y' || noCream == 'Y');
  printf(" 3 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n\n", medium == 'l' || medium == 'L', medium == 'm' || medium == 'M', medium == 'r' || medium == 'R', w1000, w1000 / GRAMS_IN_LBS, noCream == 'y' || noCream == 'Y');

  printf("Enter how you like your coffee...\n\n");
  printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
  scanf(" %c", &typeInput);
  printf("Do you like your coffee with cream ([Y]es,[N]o): ");
  scanf(" %c", &creamInput);
  printf("Typical number of daily servings: ");
  scanf("%d", &servInput);

  printf("\nThe below table shows how your preferences align to the available products:\n\n");

  printf("--------------------+-------------+-------+\n");
  printf("  |     Coffee      |  Packaged   | With  |\n");
  printf("ID|      Type       | Bag Weight  | Cream |\n");
  printf("--+-----------------+-------------+-------+\n");
  printf(" 1|       %d         |      %d      |   %d   |\n", typeInput == 'l' || typeInput == 'L', servInput >= 1 && servInput <= 4, creamInput == yesCream);
  printf(" 2|       %d         |      %d      |   %d   |\n", typeInput == 'r' || typeInput == 'R', servInput >= 5 && servInput <= 9, creamInput == noCream);
  printf(" 3|       %d         |      %d      |   %d   |\n\n", typeInput == 'm' || typeInput == 'M', servInput >= 10, creamInput == noCream);

  printf("Enter how you like your coffee...\n\n");
  printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
  scanf(" %c", &typeInput);
  printf("Do you like your coffee with cream ([Y]es,[N]o): ");
  scanf(" %c", &creamInput);
  printf("Typical number of daily servings: ");
  scanf("%d", &servInput);

  printf("\nThe below table shows how your preferences align to the available products:\n\n");

  printf("--------------------+-------------+-------+\n");
  printf("  |     Coffee      |  Packaged   | With  |\n");
  printf("ID|      Type       | Bag Weight  | Cream |\n");
  printf("--+-----------------+-------------+-------+\n");
  printf(" 1|       %d         |      %d      |   %d   |\n", typeInput == 'l' || typeInput == 'L', servInput >= 1 && servInput <= 4, creamInput == 'y' || creamInput == 'Y');
  printf(" 2|       %d         |      %d      |   %d   |\n", typeInput == 'r' || typeInput == 'R', servInput >= 5 && servInput <= 9, creamInput == 'n' || creamInput == 'N');
  printf(" 3|       %d         |      %d      |   %d   |\n\n", typeInput == 'm' || typeInput == 'M', servInput >= 10, creamInput == 'n' || creamInput == 'N');

  printf("Hope you found a product that suits your likes!\n");

  return 0;
}
