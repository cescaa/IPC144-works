/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P2)
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
    float smallShirt, mediumShirt, largeShirt;                  // shirt prices
    const char patSize = 'S', salSize = 'M', tomSize = 'L';     // vars for shoppers' sizes
    float subTotalCentsPat, subTotalCentsSal, subTotalCentsTom; // subtotals in cents
    int numOfShirtsPat, numOfShirtsSal, numOfShirtsTom;         // vars for number of shirts input
    const double TAX = 0.13;

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

    // GET NUM OF EACH SHIRT SIZE
    // User input of number of shirts for PATTY
    printf("Patty's shirt size is \'%c\'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &numOfShirtsPat);
    printf("\n");

    // User input of number of shirts for TOMMY
    printf("Tommy's shirt size is \'%c\'\n", tomSize);
    printf("Number of shirts Tommy is buying: ");
    scanf("%d", &numOfShirtsTom);
    printf("\n");

    // User input of number of shirts for SALLY
    printf("Sally's shirt size is \'%c\'\n", salSize);
    printf("Number of shirts Sally is buying: ");
    scanf("%d", &numOfShirtsSal);
    printf("\n");

    // CALCULATIONS FOR SUBTOTALS, TAXES AND FINAL TOTALS
    // Calculations for PATTY
    subTotalCentsPat = ((smallShirt * numOfShirtsPat) * 100) + 0.5; // convert to cents + round up halves
    int subTotalPat = subTotalCentsPat;                             // convert to integer
    int taxesPat = (TAX * subTotalPat) + 0.5;                       // round up half cents
    int totalPat = subTotalPat + taxesPat;

    // Calculations for TOMMY
    subTotalCentsTom = ((largeShirt * numOfShirtsTom) * 100) + 0.5;
    int subTotalTom = subTotalCentsTom;
    int taxesTom = (TAX * subTotalTom) + 0.5;
    int totalTom = subTotalTom + taxesTom;

    // Calculations for SALLY
    subTotalCentsSal = ((mediumShirt * numOfShirtsSal) * 100) + 0.5;
    int subTotalSal = subTotalCentsSal;
    int taxesSal = (TAX * subTotalSal) + 0.5;
    int totalSal = subTotalSal + taxesSal;

    // MAIN TOTALS
    float subTotalMain, taxTotalMain, totalMain;

    subTotalMain = subTotalPat + subTotalTom + subTotalSal;
    taxTotalMain = taxesPat + taxesTom + taxesSal;
    totalMain = subTotalMain + taxTotalMain;

    // Coin Breakdown for $323.5100 (subTotalMain)
    float subToon, subLoon, subQuart, subDime, subNick, subPenn;
    int remToon, remLoon, remQuart, remDime, remNick, remPenn;

    subToon = subTotalMain / 200;        // qty
    remToon = ((int)subTotalMain % 200); // balance

    subLoon = remToon / 100;
    remLoon = ((int)remToon % 100);

    subQuart = remLoon / 25;
    remQuart = ((int)remLoon % 25);

    subDime = remQuart / 10;
    remDime = ((int)remQuart % 10);

    subNick = remDime / 5;
    remNick = ((int)remDime % 5);

    subPenn = remNick / 1;
    remPenn = ((int)remNick % 1);

    // Avergae sub-cost per shirt
    float shirtCostAvgSub = subTotalMain / (numOfShirtsPat + numOfShirtsSal + numOfShirtsTom);

    // Coin Breakdown for $365.5700 (totalMain)
    float totToon, totLoon, totQuart, totDime, totNick, totPenn;
    int remToon2, remLoon2, remQuart2, remDime2, remNick2, remPenn2;

    totToon = totalMain / 200;         // qty
    remToon2 = ((int)totalMain % 200); // balance

    totLoon = remToon2 / 100;
    remLoon2 = ((int)remToon2 % 100);

    totQuart = remLoon2 / 25;
    remQuart2 = ((int)remLoon2 % 25);

    totDime = remQuart2 / 10;
    remDime2 = ((int)remQuart2 % 10);

    totNick = remDime2 / 5;
    remNick2 = ((int)remDime2 % 5);

    totPenn = remNick2 / 1;
    remPenn2 = ((int)remNick2 % 1);

    // Average sub-cost per shirt
    float shirtCostAvgTot = totalMain / (numOfShirtsPat + numOfShirtsSal + numOfShirtsTom);

    /////// FINAL FORMATING ///////
    printf("Customer Size Price Qty Sub-Total       Tax     Total\n");
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", patSize, smallShirt, numOfShirtsPat, subTotalPat / (float)100, taxesPat / (float)100, totalPat / (float)100);
    printf("Sally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", salSize, mediumShirt, numOfShirtsSal, subTotalSal / (float)100, taxesSal / (float)100, totalSal / (float)100);
    printf("Tommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", tomSize, largeShirt, numOfShirtsTom, subTotalTom / (float)100, taxesTom / (float)100, totalTom / (float)100);
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("%33.4lf %9.4lf %9.4lf\n\n", subTotalMain / (float)100, taxTotalMain / (float)100, totalMain / (float)100);

    printf("Daily retail sales represented by coins\n");
    printf("=======================================\n\n");

    printf("Sales EXCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("              %8.4lf\n", (subTotalMain) / (float)100);

    printf("Toonies  %d  %8.4lf\n", (int)subToon, remToon / (float)100);
    printf("Loonies    %d  %8.4lf\n", (int)subLoon, remLoon / (float)100);
    printf("Quarters   %d  %8.4lf\n", (int)subQuart, remQuart / (float)100);
    printf("Dimes      %d  %8.4lf\n", (int)subDime, remDime / (float)100);
    printf("Nickels    %d  %8.4lf\n", (int)subNick, remNick / (float)100);
    printf("Pennies    %d  %8.4lf\n\n", (int)subPenn, remPenn / (float)100);

    printf("Average cost/shirt: $%0.4lf\n\n", shirtCostAvgSub / (float)100);

    printf("Sales INCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("              %8.4lf\n", (totalMain) / (float)100);

    printf("Toonies  %d  %8.4lf\n", (int)totToon, remToon2 / (float)100);
    printf("Loonies    %d  %8.4lf\n", (int)totLoon, remLoon2 / (float)100);
    printf("Quarters   %d  %8.4lf\n", (int)totQuart, remQuart2 / (float)100);
    printf("Dimes      %d  %8.4lf\n", (int)totDime, remDime2 / (float)100);
    printf("Nickels    %d  %8.4lf\n", (int)totNick, remNick2 / (float)100);
    printf("Pennies    %d  %8.4lf\n\n", (int)totPenn, remPenn2 / (float)100);

    printf("Average cost/shirt: $%0.4lf\n\n", (shirtCostAvgTot / (float)100));

    return 0;
}