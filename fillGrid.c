#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int userInput();
void fillGrid();
void shuffle(char *array, int n);

int main(){
	fillGrid();

	return 0;
}

int userInput(){
	int difficulty;
	printf("enter difficulty, 1, 2 or 3 ");
	scanf("%d\n", &difficulty);
	
	return difficulty;	
}

void fillGrid(){
	srand(time(NULL));
	int difficulty = userInput();
	int numPairs, numCards;
	int dimensions = difficulty*2;
	char matrix[dimensions][dimensions];
	char random = rand() % 18 + ' ';
	char array[numCards];

	if(difficulty == 1){
		numPairs = difficulty * 2;
	}else if(difficulty == 2){
		numPairs = difficulty * 4;
	}else if(difficulty == 3){
		numPairs = difficulty * 6;
	}

	numCards = numPairs * 2;

	for(int i = 0; i < numCards; i++){
		array[i] = random;
		array[i]=random;
		i++;
		array[i] = random;
		random = rand() % 18 + ' ';
	}
	for(int i = 0; i < numCards; i++){
	}


	shuffle(array, numCards);

	int newIndex = 0;

	for(int a = 0; a < dimensions; a++){
		for(int b = 0; b < dimensions; b++){
			matrix[a][b] = array[newIndex++];
			printf("%c", matrix[a][b]);

		}
		printf("\n");
	}
}

void shuffle(char *array, int n) {
    srand((unsigned)time(NULL));
    for (int i = 0; i < n - 1; i++) {
        size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
        int t = array[j];
        array[j] = array[i];
        array[i] = t;
    }
}
