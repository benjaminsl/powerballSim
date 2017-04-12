/* *** This program simulates a person playing the powerball
   *** everyday and stops once a certain number of balls
   *** match. Ther user decides how many balls should match
   *** before stopping. */

/* DEFINTIONS:
   redball and powerball refer to the same thing
*/

#include <stdio.h>
#include <stdlib.h>
/* for rand(), srand() */
#include <stdbool.h>
#include <time.h>
/* for time(), to seed srand() */

/* functions to get user input for program options */
#include "options.h"

/* functions to do the calculation */
#include "calc.h"

/* functions for output */
#include "output.h"

int main(void)
{
	/* customer ticket, powerball drawing */
	int ticket[6] = {0};
	int draw[6] = {0};

	/* how many in-program days have we been playing? */
	int days = 0;
	int years = 0;

	/* how much did the player win? */
	int winnings = 0;

	/* Intializes random number generator */
	srand(time(NULL));

	/* do the powerballs match? */
	bool powerballsMatch = false;

	/* how many elements are equal */
	int equalElements = 0;

	/* how many equal elements to stop at */
	int stopAtThisManyMatches = 0;

	/* use new ticket everyday? */
	bool newTicketEveryday = false;

	/* do the powerballs have to match? */
	bool mustPowerballsMatch = false;

	/* ask how many numbers to match */
	printf("Stop after how many numbers match?: ");
	scanf("%d", &stopAtThisManyMatches);

	/* ask if powerballs must match */
	mustPowerballsMatch = askIfPowerballsShouldMatch();	

	/* ask if ticket should be new everday */
	newTicketEveryday = getTicketOption();

	/* very input input for stopAtThisManyMatches */
	if (stopAtThisManyMatches < 1 || stopAtThisManyMatches > 6)
	{
		printf("Number must be between 1 - 6.\n");
		return 0;
	}
	
	printf("\n"); // new line

	/* if the powerballs don't have to match */
	if (mustPowerballsMatch == false)
	{
		while (equalElements < stopAtThisManyMatches)
		{ 
			/* randomize ticket, draw */

			/* If the user wants to user the same ticket every day,
       * I will only randomize the array ticket[] on the first day. */
      if (newTicketEveryday == false)
			{	
				/* only randomize array on first day */ 
				if (days == 0) randomizeArray(ticket);
			}

			/* If the user want a different ticket every day */
			else randomizeArray(ticket);
			randomizeArray(draw);

			/* see if powerballs match */
			powerballsMatch = checkPowerballs(ticket, draw);

			/* compare the arrays */
			equalElements = compareArrays(ticket, draw, powerballsMatch);	

			/* print the arrays */
			printArray(ticket);
			printArray(draw);

			/* print a space */
			printf("\n");

			days++;	
		}
	}

	/* if powerballs must match */
	else if (mustPowerballsMatch == true)
	{
		while (equalElements < stopAtThisManyMatches || powerballsMatch == false)
		{ 
			/* randomize ticket, draw */

			/* If the user wants to user the same ticket every day,
       * I will only randomize the array ticket[] on the first day. */
      if (newTicketEveryday == false)
			{	
				/* only randomize array on first day */ 
				if (days == 0) randomizeArray(ticket);
			}
			else randomizeArray(ticket);
			randomizeArray(draw);

			/* see if powerballs match */
			powerballsMatch = checkPowerballs(ticket, draw);

			/* compare the arrays */
			equalElements = compareArrays(ticket, draw, powerballsMatch);	

			/* print the arrays */
			printArray(ticket);
			printArray(draw);

			/* print a space */
			printf("\n");
			days++;	
		}
	}

	/* Tell the user have many days they have played. */

	/* Tell the user have many days they have played. */
	printf("You bought %d tickets.\n", days);

	if (days <= 365)
	{
		printf("You have played for %d days.\n", days);
		printf("You spent $%d.\n", days * 2);
	}

	else 
	{
		years = days / 365;
		days = days - (years * 365);
		printf("You have played for %d years and %d days.\n", years, days);				
		printf("You spent $%d.\n", ((years * 365) + days) * 2);
	}

	printf("\n");

	/* do the powerballs match */
	if (powerballsMatch == false)
	{
		printf("Powerballs do not match.\n");
	}

	else if (powerballsMatch == true)
	{
		printf("Powerballs match.\n");
	}	

	winnings = amountWon(equalElements, powerballsMatch);

	if (winnings == 999) printf("You won the jackpot.\n");
	else printf("You won $%d.\n", winnings);

	return 0;
}
