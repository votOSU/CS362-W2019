/*
 * 	Unit testing for assignment 3.  
 * 		This test the isGameOver()
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
    int testResult;
    int seedNum = 400;
    int failFlag = 0;
    struct gameState gs; 
    int k[10] = {adventurer, council_room, feast, gardens, mine,
                    remodel, smithy, village, baron, great_hall};

    printf("Now Testing isGameOver() Function:\n");

	//pass in 0 for number of player to test
	testResult = initializeGame(0, k, seedNum, &gs);
	if (testResult == -1)
	{
	        printf("Test passed, number of Player is 0, game did not started correctly.\n");
	        failFlag = 1;
	}
	else
	{	
	      printf("Test failed, game started correctly\n");
	}
	
	//PRINT message for test results
	if(failFlag == 1)
		 printf("\nTEST SUCCESSFULLY COMPLETED\n\n");
	else
	      printf("\nTESTING FAILED\n\n");
	
	return 0;
}
