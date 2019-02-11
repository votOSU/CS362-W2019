/*Unitt testing for assignment 3.  
	This is a card test for the great hall card
*/


#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <assert.h>


int main() 
{
    int seedNumber = 200;
    int failFlag = 0;
    int numberOfPlayer = 2;
    int currentPlayer = 0;
    struct gameState gs, gs2;
    int k[10] = {adventurer, council_room, feast, embargo, mine, minion, smithy, village, baron, great_hall};
	printf("\nNow Testing the great hall card\n");
    initializeGame(numberOfPlayer, k, seedNumber, &gs);
    memcpy(&gs2, &gs, sizeof(struct gameState));

	    gs2.hand[currentPlayer][gs2.handCount[currentPlayer]] = great_hall;
    gs2.handCount[currentPlayer]++;
    if (gs.handCount[currentPlayer] + 1 == gs2.handCount[currentPlayer])
        printf("Passed, player have the great hall card\n");
    else
    {
        printf("Failed player do not have the great hall card\n");
        failFlag = 1;
    }

	cardEffect(great_hall, 0, 0, 0, &gs2, gs2.hand[currentPlayer][gs2.handCount[currentPlayer]-1], 0);

	    if (gs.numActions + 1 == gs2.numActions)
        printf("Passed, 1 actions gained.\n");
    else
    {
        printf("Failed, 1 actions was NOT gained.\n");
        failFlag = 1;
    }

	if(failFlag == 0)
		printf("\nTEST SUCCESSFULLY COMPLETED\n\n");
	else
		printf("\nTESTING FAILED\n\n");
    return 0;

}
