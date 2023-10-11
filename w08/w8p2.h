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

// macros
#define MAX_PRODUCTS 3    // max number of products to analyze
#define SERV_GRAMS 64     // grams in suggested serving
#define NUM_OF_TESTS 3    // for helper functions
#define LBS_TO_KG 2.20462 // lbs to kg conversion
// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
  int sku;
  double price;
  int cals;
  double weightLbs;
};

struct ReportData
{
  int sku;
  double price;
  int cals;
  double weightLbs;
  double weightKg;
  int weightGr;
  double servs;
  double costPerServ;
  double calsPerServ;
};

// ----------------------------------------------------------------------------
// function prototypes

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int *intPointer);
// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double *doubPointer);
// 3. Opening Message (include the number of products that need entering)
void openingMessage();
// 4. Get user input for the details of cat food product
void getCatFoodInfo(int intPointer, double doubPointer, struct CatFoodInfo *product, int counter);
// 5. Display the formatted table header
void displayCatFoodHeader(void);
// 6. Display a formatted record of cat food data
void displayCatFoodData(struct CatFoodInfo product);

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double *lbsPointer, double *KgResult);
// 9. convert lbs: g
int convertLbsG(const double *lbsPointer, int *GResult);
// 10. convert lbs: kg / g
void convertLbs(const double *lbsPointer, double *KgResult, int *GResult);
// 11. calculate: servings based on gPerServ
double calculateServings(const int serv, const int totalGrams, double *numOfServ);
// 12. calculate: cost per serving
double calculateCostPerServing(const double *price, const double *numOfServ, double *costPerServ);
// 13. calculate: cost per calorie
double calculateCostPerCal(const double *price, const double *calories, double *costPerCalorie);
// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo product);

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData report, const int cheapest, int cheapIdx);

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo product);
// ----------------------------------------------------------------------------

// 7. Logic entry point
void start();