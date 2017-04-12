#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

/* a function to get random numbers for ticket and powerball */
void randomizeArray(int array[]);

/* compare the arrays to see if they are equal */
int compareArrays(int array1[], int array2[], bool powerballsMatch);

/* how much has player won */
int amountWon(int equalElements, bool powerballsMatch);

/* check if powerballs match */
bool checkPowerballs(int array1[], int array2[]);
