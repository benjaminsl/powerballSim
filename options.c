#include <stdio.h>
#include <stdbool.h>
/* for type bool */

/* do powerballs have to match */
bool askIfPowerballsShouldMatch(void)
{
  int answer = false;

  /* ask the user if powerballs must match */
	printf("\n"); // new line
  printf("Must powerballs match?\n");
  printf("Type 1 for yes or 2 for no: ");

  /* get the answer */
  scanf("%d", &answer);

  /* return result */
  if (answer == 1) return true;
  else if (answer == 2) return false;
  /* return false in case they type something else */
  return true;
}

/* new ticket or same ticket */
bool getTicketOption(void)
{
  int answer = false;

  /* ask the user if powerballs must match */
	printf("\n"); // new line
  printf("Use new ticket everyday or same ticket everyday?\n");
  printf("Type 1 for new ticket or 2 for same tikcet: ");

  /* get the answer */
  scanf("%d", &answer);

  /* return result */
  if (answer == 1) return true;
  else if (answer == 2) return false;
  /* return false in case they type something else */
	return true;
}
