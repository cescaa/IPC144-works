/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 1
Full Name  : Anna Francesca Dela Cruz
Student ID#: 123123150
Email      : afgdela-cruz@myseneca.ca
Section    : NJJ

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

// max length of string input
#define MAX_INPUT_LENGTH 31

// Clear the standard input buffer
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue
void suspend(void);

// ONE: get integer from keyboard
int inputInt();

// TWO: get POSITIVE integer
int inputIntPositive();

// THREE: get integer BETWEEN a range
int inputIntRange(int lower, int upper);

// FOUR: get char that's also in given arr
char inputCharOption(const char stringArr[]);

// FIVE: get string between given range
void inputCString(char *cstringValue, int min, int max);

// SIX: validate phone number
void displayFormattedPhone(const char *phoneNum);
