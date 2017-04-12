#include <stdbool.h>
/* for type bool */
#include <stdlib.h>
/* for rand() */

/* checks if powerballs match */
bool checkPowerballs(int array1[], int array2[])
{
	/* If the powerball of the user's ticket (array1[5])
   * matches ( == ) the powerball of the drawing (array[5]),
   * then return true. */
	if (array1[5] == array2[5]) return true;
	else return false;
}

/* This function gets random numbers for an array in
 * the range [1, 69] for first five numbers and [0, 26] */
void randomizeArray(int array[])
{
  /* make the first five elements of the array */
  /* a random number between 1 and 69 */
  array[0] = (rand() % 69) + 1;

  /* ___________________________________________ */

  array[1] = (rand() % 69) + 1;

  /* make sure the same number isn't drawn again*/
  while (array[1] == array[0])
  {
    array[1] = (rand() % 69) + 1;
  }

  /* ___________________________________________ */

  array[2] = (rand() % 69) + 1;

  /* make sure the same number isn't drawn again*/
  while (array[2] == array[1] || array[2] == array[0])
  {
    array[2] = (rand() % 69) + 1;
  }

  /* ___________________________________________ */

  array[3] = (rand() % 69) + 1;

  /* make sure the same number isn't drawn again*/
  while (array[3] == array[2] || array[3] == array[1] || array[3] == array[0])
  {
    array[3] = (rand() % 69) + 1;
  }

  /* ___________________________________________ */

  array[4] = (rand() % 69) + 1;
  /* make sure the same number isn't drawn again*/
  while (array[4] == array[3] || array[4] == array[2] || array[4] == array[1] || array[4] == array[0])
  {
    array[4] = (rand() % 69) + 1;
  }

  /* ___________________________________________ */

  /* make the last element the powerball - it can be */
  /* 1 to 26 */
  array[5] = (rand() % 26) + 1;

  /* ___________________________________________ */

  return;
}

  /* returns how many elements are equal */
int compareArrays(int array1[], int array2[], bool powerballsMatch)
{
  /* index */
  int i, j;

  /* how many equal elements */
  int equalElements = 0;

  for (i = 0; i < 4; i++)
  {
    for (j = 0; j < 4; j++)
    {
      if (array1[i] == array2[j])
      {
        equalElements++;
      }
    }
  }

  /* if the powerballs match, add 1 to equalElements */
  if (powerballsMatch == true) equalElements++;

  return equalElements;
}

/* This function returns how much the player won. */
int amountWon(int equalElements, bool powerballsMatch)
{
  int winnings = 0;

  /* one number mathces */
  if (equalElements == 1 && powerballsMatch == false) winnings = 0;
  /* and powerball matches */
  else if (equalElements == 1 && powerballsMatch == true) winnings = 4;

  /* two numbers mathces */
  else if (equalElements == 2 && powerballsMatch == false) winnings = 0;
  /* and powerball matches */
  else if (equalElements == 2 && powerballsMatch == true) winnings = 4;

  /* three numbers mathces */
  else if (equalElements == 3 && powerballsMatch == false) winnings = 7;
  /* and powerball matches */
  else if (equalElements == 3 && powerballsMatch == true) winnings = 7;

  /* four numbers mathces */
  else if (equalElements == 4 && powerballsMatch == false) winnings = 100;
  /* and powerball matches */
  else if (equalElements == 4 && powerballsMatch == true) winnings = 100;

  /* five numbers mathces */
  else if (equalElements == 5 && powerballsMatch == false) winnings = 1000000;
  /* and powerball matches */
  else if (equalElements == 5 && powerballsMatch == true) winnings = 50000;

  /* six number match */
  /* if six numbers, match, powerball has to match */
  else if (equalElements == 6) winnings = 999;

  else winnings = 0;

  return winnings;
}
