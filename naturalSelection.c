#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

extern int bias(int bias, int currentNode);
extern void output(int node, int status, int nodeBias);

int main(int argc, char **argv){
	srand(time(NULL));

	int currentBias = rand() % 10 + 1;

	int firstNodeGeneration = 1,
	    secondNodeGeneration = 1,
	    thirdNodeGeneration = 1,
	    fourthNodeGeneration = 1,
	    fifthNodeGeneration = 1,
	    sixthNodeGeneration = 1;
	
	int firstNode = 1, 
	    secondNode = 1, 
	    thirdNode = 1,
	    fourthNode = 1,
	    fifthNode = 1,
	    sixthNode = 1;

	int firstNodeBias = rand() % 10,
	    secondNodeBias = rand() % 10,
	    thirdNodeBias = rand() % 10,
	    fourthNodeBias = rand() % 10,
	    fifthNodeBias = rand() % 10,
	    sixthNodeBias = rand() % 10;

	if (argv[1]!=NULL)
		while (1){
			currentBias = rand() % 10 + 1;
	
			int firstNode = 1, 
			    secondNode = 1, 
			    thirdNode = 1,
			    fourthNode = 1,
			    fifthNode = 1,
			    sixthNode = 1;		

			for (int i = 0; i <= atoi(argv[1]); i++) {

			system("clear");
			printf("%d\n", currentBias);
			
			if (firstNode == 0) firstNodeBias = 0;
			else { 
				firstNodeBias += rand() % 8; 
				firstNodeGeneration++;
			}

			if (secondNode == 0) secondNodeBias = 0;
			else { 
				secondNodeBias += rand() % 8;
				secondNodeGeneration++;
			}

			if (thirdNode == 0) thirdNodeBias = 0;
			else { 
				thirdNodeBias += rand() % 8;
				thirdNodeGeneration++;
			}

			if (fourthNode == 0) fourthNodeBias = 0;
			else { 
				fourthNodeBias += rand() % 8;
				fourthNodeGeneration++;
			}

			if (fifthNode == 0) fifthNodeBias = 0;
			else {
				fifthNodeBias += rand() % 8;
				fifthNodeGeneration++;
			}

			if (sixthNode == 0) sixthNodeBias = 0;
			else {
				sixthNodeBias += rand() % 8;
				sixthNodeGeneration++;
			}

			output(1, firstNode, firstNodeBias);
			output(2, secondNode, secondNodeBias);
			output(3, thirdNode, thirdNodeBias);
			output(4, fourthNode, fourthNodeBias);
			output(5, fifthNode, fifthNodeBias);
			output(6, sixthNode, sixthNodeBias);

			if (bias(firstNodeBias, currentBias) == 0) 
				firstNode = 0;
			if (bias(secondNodeBias, currentBias) == 0) 
				secondNode = 0;
			if (bias(thirdNodeBias, currentBias) == 0) 
				thirdNode = 0;
			if (bias(fourthNodeBias, currentBias) == 0) 
				fourthNode = 0;
			if (bias(fifthNodeBias, currentBias) == 0) 
				fifthNode = 0;
			if (bias(sixthNodeBias, currentBias) == 0) 
				sixthNode = 0;

			currentBias += rand() % 7;
		}
	
	printf("\n1: %d\n2: %d\n3: %d\n4: %d\n5: %d\n6: %d\n",
			firstNodeGeneration,
			secondNodeGeneration,
			thirdNodeGeneration,
			fourthNodeGeneration,
			fifthNodeGeneration,
			sixthNodeGeneration);
	sleep(5);
		}

	return 0;
}

int bias(int bias, int currentNode){
	if (bias <= currentNode)
		return 1;
	return 0;
}

void output(int node, int status, int currentBias){
	printf("[%d]: %d, %d\n", node, status, currentBias);
}
