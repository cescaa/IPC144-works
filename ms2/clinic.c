/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 2
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
#include <string.h>
// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"

//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
           "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient *patient, int fmt)
{
    if (fmt == FMT_FORM) // if input is 1

    {
        printf("Name  : %s\n"
               "Number: %05d\n"
               "Phone : ",
               patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else // if input is 2
    {
        printf("%05d %-15s ", patient->patientNumber,
               patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}

//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData *data)
{
    int selection;

    do
    {
        printf("Veterinary Clinic System\n"
               "=========================\n"
               "1) PATIENT     Management\n"
               "2) APPOINTMENT Management\n"
               "-------------------------\n"
               "0) Exit System\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            printf("<<< Feature not yet available >>>\n\n");
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do
    {
        printf("Patient Management\n"
               "=========================\n"
               "1) VIEW   Patient Data\n"
               "2) SEARCH Patients\n"
               "3) ADD    Patient\n"
               "4) EDIT   Patient\n"
               "5) REMOVE Patient\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient *patient)
{
    int selection;

    do
    {
        printf("Edit Patient (%05d)\n"
               "=========================\n"
               "1) NAME : %s\n"
               "2) PHONE: ",
               patient->patientNumber, patient->name);

        displayFormattedPhone(patient->phone.number);

        printf("\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            clearInputBuffer();
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}

/////////////////////////////// ****** MS2 functions written by Anna Francesca Dela Cruz ~ START ****** ///////////////////////////////

// Display's all patient data in the FMT_FORM | FMT_TABLE format
void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    displayPatientTableHeader();
    int i;
    for (i = 0; i < max; i++)
    {

        if (patient[i].patientNumber != 0)
        {

            printf("%d  %-15s ", patient[i].patientNumber, patient[i].name);
            displayFormattedPhone(patient[i].phone.number);
            printf(" (%s)\n", patient[i].phone.description);
        }
    }
    printf("\n");
}

// Search for a patient record based on patient number or phone number
void searchPatientData(const struct Patient patient[], int max)
{
    int searchSel;

    printf("Search Options\n==========================\n1) By patient number\n2) By phone number\n..........................\n0) Previous menu\n..........................\nSelection: ");
    scanf("%d", &searchSel);
    printf("\n");

    if (searchSel == 2)
    {
        searchPatientByPhoneNumber(patient, max); // search by phone
        printf("\n");
        clearInputBuffer();
        suspend();
        searchPatientData(patient, max); // show menu again
    }
    else if (searchSel == 1)
    {
        searchPatientByPatientNumber(patient, max); // search by patient
        printf("\n");
        clearInputBuffer();
        suspend();
        searchPatientData(patient, max);
    }
}

// Add a new patient record to the patient array
void addPatient(struct Patient patient[], int max)
{
    int flag = 0;
    int i;
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber == 0) // if there is room in the patient array
        {
            int newPatientNum = nextPatientNumber(patient, max); // Get the next highest patient number
            patient[i].patientNumber = newPatientNum;            // enter new patient num in array
            inputPatient(&patient[i]);                           // Get user input for rest of the new patient's info
            printf("\n*** New patient record added ***\n\n");
            clearInputBuffer();
            flag = 1;
            i = max;
        }
    }

    if (i == max && flag == 0) // if no room in patient array
    {
        printf("ERROR: Patient listing is FULL!\n\n");
    }
}

// Edit a patient record from the patient array
void editPatient(struct Patient patient[], int max)
{
    int patientNumber;
    printf("Enter the patient number: ");
    scanf("%d", &patientNumber);
    printf("\n");

    // Find the patient array index by patient number (returns -1 if not found)
    int patientIdx = findPatientIndexByPatientNum(patientNumber, patient, max);

    if (patientIdx != -1) // if patient is found user can edit
    {
        menuPatientEdit(&patient[patientIdx]);
    }
    else
    {
        printf("ERROR: Patient record not found!\n");
    }
}

// Remove a patient record from the patient array
void removePatient(struct Patient patient[], int max)
{
    int patientNumber;
    printf("Enter the patient number: ");
    scanf("%d", &patientNumber);
    printf("\n");
    int patientIdx = findPatientIndexByPatientNum(patientNumber, patient, max); // find patient
    char answer;
    if (patientIdx != -1) // if pateint is found
    {
        displayPatientData(&patient[patientIdx], FMT_FORM); // show patient data
        printf("\nAre you sure you want to remove this patient record? (y/n): ");
        scanf(" %c", &answer);
        clearInputBuffer();

        if (answer == 'y')
        {
            patient[patientIdx].patientNumber = 0; // change patient number to 0 to show patient has been deleted
            printf("Patient record has been removed!\n\n");
        }
        else
        {
            printf("Operation aborted.\n");
        }
    }
    else
    {
        printf("ERROR: Patient record not found!\n");
    }
}

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
    int patientNumber;
    printf("Search by patient number: ");
    scanf("%d", &patientNumber);
    printf("\n");
    int patientIdx = findPatientIndexByPatientNum(patientNumber, patient, max); // find patient
    if (patientIdx != -1)                                                       // if patient is found
    {
        displayPatientData(&patient[patientIdx], FMT_FORM); // display patient info
    }
    else
    {
        printf("*** No records found ***\n");
    }
}

// Search and display patient records by phone number (tabular)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    int flag = 0;

    char patientPhone[PHONE_LEN + 1];
    printf("Search by phone number: ");
    scanf("%s", patientPhone);
    printf("\n");
    displayPatientTableHeader();
    int i;
    for (i = 0; i < max; i++)
    {
        if (strcmp(patientPhone, patient[i].phone.number) == 0) // check if user's input of phone num matches a patient's phone num in the record
        {
            // display patient's info of matching phone num
            printf("%d  %-15s ", patient[i].patientNumber, patient[i].name);
            displayFormattedPhone(patient[i].phone.number);
            printf(" (%s)\n", patient[i].phone.description);
            flag = 1;
        }
        else if ((strcmp(patientPhone, patient[i].phone.number) != 0) && i == max - 1 && flag == 0)
        {
            printf("\n*** No records found ***\n");
        }
    }
}

// Get the next highest patient number
int nextPatientNumber(const struct Patient patient[], int max)
{
    int highestNum = 0;
    int i;
    for (i = 0; i < max; i++)
    {
        if (highestNum < patient[i].patientNumber)
        {
            highestNum = patient[i].patientNumber;
        }
    }
    return highestNum + 1;
}

// Find the patient array index by patient number (returns -1 if not found)
int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max)
{
    int result = -1;
    int i;
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber == patientNumber)
        {
            result = i;
        }
    }
    return result;
}

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
void inputPatient(struct Patient *patient)
{
    printf("Patient Data Input\n------------------\n");
    printf("Number: 0%d\n", patient->patientNumber);
    printf("Name  :  ");
    scanf("%s", patient->name);
    clearInputBuffer();
    printf("\n");
    inputPhoneData(&patient->phone); // get phone info
}

// Get user input for phone contact information
void inputPhoneData(struct Phone *phone)
{
    int selection;
    printf("Phone Information\n-----------------\nHow will the patient like to be contacted?\n1. Cell\n2. Home\n3. Work\n4. TBD\nSelection: ");
    scanf("%d", &selection);
    printf("\n");

    // depending on selection, add new patient's number and phone description
    switch (selection)
    {
    case 1: // if user selects CELL
        printf("Contact: CELL");
        printf("Number : ");
        scanf("%s", phone->number); // add phone number
                                    // add phone descrip
        break;
    case 2:

        printf("Contact: HOME");
        printf("Number : ");
        scanf("%s", phone->number);
        // strcpy(phone->description, "HOME"); was having issues with this

        break;
    case 3:
        printf("Number : WORK");
        scanf("%s", phone->number);
        //  strcpy(phone->description, "WORK");
        break;
    case 4:
        // strcpy(phone->description, "TBD");
        break;
    }
}
