/*
 * 	Unit testing for assignment 3.  
 * 		This test the buyCard()
 * 		*/

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
	int failFlag = 0;	//for flagging the fails
	int testResult;
	
	
	printf("Now Testing the buyCard() function:\n");
	gs.numBuys = 1;
	gs.coins = 1;
	
	
 	testResult = buyCard(5, &gs);
	if(testResult == -1)
	{	
		printf("Enough Coins?\n");	
		printf("No, we don't have enough to buy, test passed\n");	
	}
	else
	{	
		printf("Enough Coins?\n");
		printf("Yes, we have enough to buy, test failed, \n");
		failFlag = 1;
	}	
		
	//PRINT message for test results
	if(failFlag == 0)
		printf("\nTEST SUCCESSFULLY COMPLETED\n\n");
	else
		printf("\nTESTING FAILED\n\n");
								
	return 0;	
}
