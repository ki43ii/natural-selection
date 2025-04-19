#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <math.h>

extern int  bias(int bias, int currentNode);
extern void output(int node, int status, int nodeBias);
extern void outputGenerations(int node, int generations);

typedef struct {
	int node,
	    status,
	    population,
	    generation;
} node;

#define alive 1
#define dead 0

int main(int argc, char **argv){
	srand(time(NULL));

	char *flag = argv[3];

	int generation = 1;

	node first  = 	{1, alive, rand() % 10, generation},
	     second = 	{2, alive, rand() % 10, generation},
	     third  = 	{3, alive, rand() % 10, generation},
	     fourth = 	{4, alive, rand() % 10, generation},
	     fifth  = 	{5, alive, rand() % 10, generation},
	     sixth  = 	{6, alive, rand() % 10, generation}; 

	if (argv[1]!=NULL && argv[2] != NULL)
		while (generation <= atoi(argv[2])){
			int currentBias = rand() % 10 + 1;

			first.generation  = 0;
			second.generation = 0;
			third.generation  = 0;
			fourth.generation = 0;
			fifth.generation  = 0;
			sixth.generation  = 0;

			first.status  = alive;
			second.status = alive;
			third.status  = alive;
			fourth.status = alive;
			fifth.status  = alive;
			sixth.status  = alive;

			for (int i = 1; i <= atoi(argv[1]); i++) {

			system("clear");
			
			printf("%d\n\n", generation);
			printf("%d\n", currentBias);
			
			if (first.status == dead) first.population = 0;
			else {
				first.population += rand() % 5 + 2; 
				first.generation++;
			}

			if (second.status == dead) second.population = 0;
			else {
				second.population += ceil(currentBias / 4);
				second.generation++;
			}

			if (third.status == dead) third.population = 0;
			else {
				third.population += ceil(currentBias / 3);
				third.generation++;
			}

			if (fourth.status == dead) fourth.population = 0;
			else {
				fourth.population += rand() % 8;
				fourth.generation++;
			}

			if (fifth.status == dead) fifth.population = 0;
			else {
				fifth.population += floor(currentBias / 5) + 5;
				fifth.generation++;
			}

			if (sixth.status == dead) sixth.population = 0;
			else {
				sixth.population += ceil((currentBias + 1) / 7);
				sixth.generation++;
			}

			output(	first.node , first.status , first.population  );
			output(	second.node, second.status, second.population );
			output(	third.node , third.status , third.population  );
			output(	fourth.node, fourth.status, fourth.population );
			output( fifth.node , fifth.status , fifth.population  );
			output(	sixth.node , sixth.status , sixth.population  );

			if (bias(first.population, currentBias ) == 0) first.status  = dead;
			if (bias(second.population, currentBias) == 0) second.status = dead;
			if (bias(third.population, currentBias ) == 0) third.status  = dead;
			if (bias(fourth.population, currentBias) == 0) fourth.status = dead;
			if (bias(fifth.population, currentBias ) == 0) fifth.status  = dead;
			if (bias(sixth.population, currentBias ) == 0) sixth.status  = dead;

			currentBias += rand() % 7;

			puts("");
			outputGenerations(first.node , first.generation );
			outputGenerations(second.node, second.generation);
			outputGenerations(third.node , third.generation );
			outputGenerations(fourth.node, fourth.generation);
			outputGenerations(fifth.node , fifth.generation );
			outputGenerations(sixth.node , sixth.generation );
		
			}
	
	if(flag != NULL && argv[4] != NULL)
		if(strcmp(flag, "-t") == 0)
			sleep(atoi(argv[4]));
	generation++;
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

void outputGenerations(int node, int generations){
	printf("%d: %d\n", node, generations);
}
