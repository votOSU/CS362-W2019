/*
 * 	Unit testing for assignment 3.  
 * 		This is a card test for the smithy card
 * 		*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <assert.h>
#include "rngs.h"



int main() 
{
	
	int seedNumber = 400;
    	int failFlag = 0;
    	int numberOfPlayer = 2;
    	int currentPlayer = 0;
    	struct gameState gs, gs2;
	int k[10] = {adventurer, council_room, feast, embargo, mine, minion, smithy, village, baron, great_hall};
    
	printf("\nNow Testing the smithy card\n");
	initializeGame(numberOfPlayer, k, seedNumber, &gs);
   	memcpy(&gs2, &gs, sizeof(struct gameState));

    	///assigning smithy card
    	gs2.hand[currentPlayer][gs2.handCount[currentPlayer]] = smithy;
    	gs2.handCount[currentPlayer]++;
    	if (gs.handCount[currentPlayer] + 1 == gs2.handCount[currentPlayer])
    	 	printf("Passed the Smithy card is in hand\n");
    	else
    	{    	
	       	printf("Failed the Smithy card is not in hand\n");
    	      	failFlag = 1;
    	}
    	  	    	/// making sure of having 3 cards
    	cardEffect(smithy, 0, 0, 0, &gs2, gs2.hand[currentPlayer][gs2.handCount[currentPlayer]-1], 0);
    	if (gs.handCount[currentPlayer] + 3 == gs2.handCount[currentPlayer])
    	     	printf("Passed, have gained 3 cards.\n");
    	else
    	{
    	     	printf("Failed, no cards gained\n");
    	      	failFlag = 1;
    	}

		if(failFlag == 0)
		printf("\nTEST SUCCESSFULLY COMPLETED\n\n");
	else
		printf("\nTESTING FAILED\n\n");
	return 0;
}
