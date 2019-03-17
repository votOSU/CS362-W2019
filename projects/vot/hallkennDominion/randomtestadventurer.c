
/*
 *  * 	Random testing for assignment 4.  
 *   * 		This is a card test for the adventure card
 *    * 		*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <assert.h>

int assertFlag(int number, int *passFlag);

int main() 
{
	int num_of_test = 600;
	int kc[10] = {adventurer, council_room, feast, embargo, mine, minion, smithy, village, baron, great_hall};
	int fCount = 0, sCount=0;
	int players=0, player=0, deckCount, handCount, seed=7, passFlag, lastHandCount, finalEndCard, endCard;
	struct gameState gs;
	printf("Now Testing Random Adventurer\n");
	
	for (int i = 0; i < num_of_test; i++) 
	{
		passFlag = 1;
		//number of player is 2 to 4
		do 
		{
			players = rand() % 5;
		} while (players < 2);
		gs.whoseTurn = player =  players;
		initializeGame(players, kc, seed, &gs);
		player = gs.whoseTurn;
		
		gs.deckCount[player] = rand() % MAX_DECK; 
		gs.discardCount[player] = rand() % MAX_DECK;
		gs.handCount[player] = rand() % MAX_HAND;
		lastHandCount = handCount = gs.handCount[player];	
		deckCount = gs.deckCount[player];

		if (gs.handCount[player] <= 100 && gs.handCount[player] > 2) 
		{
			//last card				 
			finalEndCard = gs.hand[player][gs.handCount[player] - 1];
			////second to last
			endCard = gs.hand[player][gs.handCount[player] - 2];
			passFlag = assertFlag(((endCard == gold || endCard == copper || endCard == silver) &&
			 (finalEndCard == gold || finalEndCard == copper || finalEndCard == silver)),&passFlag);
		}
		
		printf("Test %d of %d: ", i + 1, num_of_test);
		if (passFlag) 
		{
			printf("Test Passed. \n");
			sCount++;
		}
		else 
		{
			printf("Test Failed. \n");
			fCount++;
		}

	}

	int sumSuccess = sCount;
	int sumFailure = fCount;
	printf("\nTotal Sucess:   %d\n",sCount);
	printf("Total Fails:  %d\n",fCount);
	printf("Tests Complete\n");
	return 0;

}

int assertFlag(int number, int *passFlag) 
{
	if (!number) 
	{
		*passFlag = 0;
		return 0;
	}
	
}


