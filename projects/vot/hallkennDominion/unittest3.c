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

    int failFlag = 0;
    struct gameState gs; 


    printf("Now Testing isGameOver() Function:\n");

   
	
	//Test to see if the game continues or ended. 
	//	//with 1 province card left instead of 0.
	gs.supplyCount[province] = 1;
	printf("Current supply count for province card is: %d\n", gs.supplyCount[province]);
	if (isGameOver(&gs))
	{	
		printf("Test failed, 0 province card left, game over!\n");
		failFlag = 1;
	}
	else
	{    
		printf("Test passed, 1 province card left, game is NOT over!.\n");
	}
  	//test to see if the game continues or ended. 
	//with 1 province card left instead of 0.
	gs.supplyCount[province] = 0;
	printf("Current supply count for province card is: %d\n", gs.supplyCount[province]);
	if (isGameOver(&gs))
	{	
	        printf("Test passed, 0 province card left, game is over!\n");
      	}
        else
   	{	
 	        printf("Test failed, 1 or more province card left, game is NOT over!\n");
      		failFlag =1; 
	}
	
	//PRINT message for test results
	if(failFlag == 0)
	       printf("\nTEST SUCCESSFULLY COMPLETED\n\n");
     	else
 	      printf("\nTESTING FAILED\n\n");
        
	return 0;
}
	        					            	        	    	        					      	          
