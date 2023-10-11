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
#define MAX_PRODUCTS 3 // max number of products to analyze
#define SERV_GRAMS 64  // grams in suggested serving
#define NUM_OF_TESTS 3 // for helper functions

// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
  int sku;
  double price;
  int cals;
  double weightLbs;
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
// 7. Logic entry point
void start();