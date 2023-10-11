/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P1)
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
    char loopType;
    int numOfIterations;

    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n\n");

    do
    {
        printf("D = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &loopType, &numOfIterations);                                     // prompt user
        if (!(loopType == 'Q' || loopType == 'D' || loopType == 'W' || loopType == 'F')) // INVALID VALUES
        {
            printf("ERROR: Invalid entered value(s)!\n\n");
        }

        else if (loopType == 'D' && numOfIterations >= 3 && numOfIterations <= 20)
        {
            printf("DO-WHILE: "); //// DO-WHILE ////
            do
            {
                printf("%c", loopType);
                numOfIterations--;
            } while (numOfIterations > 0);
            printf("\n\n");
        }

        else if (loopType == 'W' && numOfIterations >= 3 && numOfIterations <= 20)
        {
            printf("WHILE   : "); //// WHILE ////
            while (numOfIterations > 0)
            {
                printf("%c", loopType);
                numOfIterations--;
            }
            printf("\n\n");
        }

        else if (loopType == 'F' && numOfIterations >= 3 && numOfIterations <= 20)
        {
            printf("FOR     : "); //// FOR ////
            for (numOfIterations = numOfIterations; numOfIterations > 0; numOfIterations--)
            {
                printf("%c", loopType);
            }
            printf("\n\n");
        }

        else if ((loopType == 'D' || loopType == 'W' || loopType == 'F') && !(numOfIterations >= 3 && numOfIterations <= 20)) //// INVALID ITERATIONS ////
        {
            printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
        }

        else if (loopType == 'Q' && !(numOfIterations == 0) && !(numOfIterations >= 3 && numOfIterations <= 20)) //// INVALID QUIT ////
        {
            printf("ERROR: To quit, the number of iterations should be 0!\n\n");
        }

        else if (loopType == 'Q' && numOfIterations == 0) //// Q
        {
            flag = 0;
        }
        else // for everything else just in case
        {
            printf("ERROR: Invalid entered value(s)!\n\n");
        }

    } while (flag == 1);

    printf("\n+--------------------+\n");
    printf("Loop application ENDED\n");
    printf("+--------------------+\n");

    return 0;
}