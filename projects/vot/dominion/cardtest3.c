/*
 * 	Unit testing for assignment 3.  
 * 		This is a card test for the adventure card
 * 		*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <assert.h>

int main() 
{
    int seedNumber = 1000;
    int failFlag = 0;
    int numberOfPlayer = 2;
    int currentPlayer = 0;
    struct gameState gs, gs2;
    int k[10] = {adventurer, council_room, feast, embargo, mine, minion, smithy, village, baron, great_hall};
	printf("\nNow Testing the adventure card\n");
    initializeGame(numberOfPlayer, k, seedNumber, &gs);
	memcpy(&gs2, &gs, sizeof(struct gameState));
	    gs2.hand[currentPlayer][gs2.handCount[currentPlayer]] = adventurer;
    gs2.handCount[currentPlayer]++;
    if (gs.handCount[currentPlayer] + 1 == gs2.handCount[currentPlayer])
        printf("Passed, player have the adventure card\n");
    else
    {
        printf("Failed player do not have the adventure card\n");
        failFlag = 1;
    }
	cardEffect(adventurer, 0, 0, 0, &gs2, gs2.hand[currentPlayer][gs2.handCount[currentPlayer]-1], 0);
	    if (gs.handCount[currentPlayer] < gs2.handCount[currentPlayer])
		printf("Passed, more cards are present\n");
	    else
   	  {
		printf("Failed, NO more cards are present\n");
		failFlag = 1;
	    }
	if(failFlag == 0)
		printf("\nTEST SUCCESSFULLY COMPLETED\n\n");
	else
		printf("\nTESTING FAILED\n\n");
	return 0;



}
