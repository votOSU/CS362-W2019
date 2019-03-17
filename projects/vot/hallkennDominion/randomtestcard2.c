
/*
 *  * 	Random testing for assignment 4.  
 *   * 		This is a card test for the isGameOver() from previous unit test in assignment 3
 *    * 		*/


#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <assert.h>
#include "rngs.h"


int main() 
{
    	int testResult, randNum;
    	int seedNum = 400;
    	int failFlag = 0;
    	struct gameState gs; 
    	int k[10] = {adventurer, council_room, feast, gardens, mine,
                    remodel, smithy, village, baron, great_hall};

    	printf("Now Randomly Testing isGameOver():\n\n");

	//Test Pass if random number is not 2, 3, or 4 
	for (int i = 0; i < 100; i++)
	{
		do
		{
			randNum = rand() % 10;	
		}while(randNum < 1);
		printf("Random NUM is: %d\n",randNum);
		testResult = initializeGame(randNum, k, seedNum, &gs);
		//printf("TestREsult is: %d\n",testResult);
		if (testResult == -1)
		{
			printf("Test passed, number of Player is 1 or greater than 4. No Game\n");
			failFlag = 1;
		}
		else
		{	
			//Failed because random number generated is 2, 3, or 4
			printf("Test failed, game started correctly\n");
		}
	}

	//PRINT message for test results
	if(failFlag == 1)
	{
		printf("\nTEST SUCCESSFULLY COMPLETED\n\n");
	}
	else
	{
		printf("\nTESTING FAILED\n\n");
	}

	return 0;

}

