
/*
 *  * 	Random testing for assignment 4.  
 *   * 		This is a card test for the buycard() from previous unit test in assignment 3
 *    * 		*/


#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <assert.h>
#include "rngs.h"


int main ()	
{
	struct gameState gs;
	int failFlag = 0, passedCounter = 0, passedSum;	//for flagging the fails
	int testResult, seed, counter; 


	printf("Now Testing the buyCard() function:\n");

	printf("\n");

	for (int i = 0; i < 1000; i++)
	{
		do
		{
			seed = rand() % 10;
		}while(seed < 2);
		gs.coins = seed;
		testResult = buyCard(5, &gs);
		if(testResult == -1)
		{	
			printf("Enough Coins?\n");	
			printf("No, we don't have enough to buy, test PASSED\n");
			passedCounter++;	
		}
		else
		{	
			printf("Enough Coins?\n");
			printf("Yes, we have enough to buy, test FAILED, \n");
			failFlag++;
		}
		passedSum = passedCounter;
		counter++;
		printf("Loop Count: %d\n\n",counter);
	}

	printf("Total PASSED: %d",passedSum);		
	//PRINT message for test results
	if(failFlag == 0)
		printf("\nTEST SUCCESSFULLY COMPLETED\n\n");
	else
		printf("\nTESTING FAILED\n\n");
	
	return 0;

}
