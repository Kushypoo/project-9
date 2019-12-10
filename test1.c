#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int userInput();
void shuffle(char array[], int dimensions);
void getPairs();

int main(){
	getPairs();

	return 0;
}

int userInput(){
	int difficulty;
	printf("enter difficulty, 1, 2 or 3 ");
	scanf("%d\n", &difficulty);
	
	return difficulty;	
}

void getPairs(){
	srand(time(NULL));
	int difficulty = userInput(), numPairs, numCards;
	int dimensions = difficulty*2;
	char matrix[dimensions][dimensions];
	char random = rand() % 31 + '!';

	if(difficulty == 1){
		numPairs = difficulty * 2;
	}else if(difficulty == 2){
		numPairs = difficulty * 4;
	}else if(difficulty == 3){
		numPairs = difficulty * 6;
	}
	numCards = numPairs * 2;
	char array[numCards];

	for(int i = 0; i < numCards; i++){
		array[i] = random;
		i++;
		array[i] = random;
		random = rand() % 31 + '!';
	}

	//shuffle(array, numCards);

	for(int i = 0; i < dimensions; i++){
		for(int j = 0; j < dimensions; j++){
			matrix[i][j] = array[i];
			printf("%c", matrix[i][j]);
		}
		printf("\n");
	}

}

void shuffle(char array[], int dimensions){
	
	int size = dimensions;

	if(size > 1){
		for(int i = 0; i < size - 1; i++){
			int j = rand() % dimensions;
			const char temp = array[j]; 
			array[j] = array[i];
			array[i] = temp;
		}
	}
}
