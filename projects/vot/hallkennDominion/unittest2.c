/*
 * 	Unit testing for assignment 3.  
 * 		This test the fullDeckCount()
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
  struct gameState gs;
  int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, 
    great_hall};
  int hand1Test[0]; 
  int deck1Test[0];
  int discardingCardTest1[0];
  int testResult;
  int failFlag = 0;	//for flagging the fails

  initializeGame(2, k, 1, &gs);
  memcpy(gs.hand[0][0], hand1Test, 0);
  memcpy(gs.deck[0][0], deck1Test, 0);
  memcpy(gs.discard[0][0], discardingCardTest1, 0);
  gs.handCount[0] = 0;
  gs.deckCount[0] = 0;
  gs.discardCount[0] = 0;

  printf("Now Testing the fullDeckCount() function:\n");

  //to see if deck is empty
  testResult = fullDeckCount(0, gold, &gs);
  if (testResult == 0)   
  {
  	printf("Test passed, deck is empty, same as 0 that was in the argument\n");
  }
  else
  {
  	printf("Test failed, deck is not empty, not the same as 0 that was in the argument.\n");
  	failFlag = 1;
  }
  //
  int hand2Test[5];
  hand2Test[0] = silver;
  hand2Test[1] = silver;
  hand2Test[2] = silver;
  hand2Test[3] = silver;
  hand2Test[4] = silver;
  memcpy(gs.hand[0], hand2Test, 5 * sizeof(int));
  gs.handCount[0] = 5;
  //
  int deck2Test[7];
  deck2Test[0] = silver;
  deck2Test[1] = silver;
  deck2Test[2] = silver;
  deck2Test[3] = silver;
  deck2Test[4] = silver;
  deck2Test[5] = silver;
  deck2Test[6] = silver;
  memcpy(gs.deck[0], deck2Test, 7 * sizeof(int));
  gs.deckCount[0] = 7;
  
  int discardingCardTest2[4];
  discardingCardTest2[0] = silver;
  discardingCardTest2[1] = silver;
  discardingCardTest2[2] = silver;
  discardingCardTest2[3] = silver;
  memcpy(gs.discard[0], discardingCardTest2, 4 * sizeof(int));
  gs.discardCount[0] = 4;
  //
  //deck already have silver, test to see if silver is there
  testResult = fullDeckCount(0, silver, &gs);
  if (testResult == 0)  
  {
  	printf("Second test passed. Card type does match.\n");
  }
  else
  { 
         printf("Second test failed. Card type does not match.\n");
         failFlag = 1;
  }
  //PRINT message for test results
  if(failFlag == 0)
         printf("\nTEST SUCCESSFULLY COMPLETED\n\n");
  else
         printf("\nTESTING FAILED\n\n");
  
  return 0;

}
                                                                                                                           
