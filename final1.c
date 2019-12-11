#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX 6
#define NMAX 100

void userInput(int grid, int* row, int* column);
void fillGrid();
void shuffle(char *array, int n);
_Bool checkMatch(int grid, int board[][MAX], int r1, int r2, int c1, int c2);
int runGame(int dimensions, int arr[][MAX]);
void displayBoard(int dimensions, int arr[][MAX], int matrix[][MAX]);
_Bool gameWon(int grid,  int correct[][MAX]);
int gameDifficulty(int difficulty);
int getMenuChoice();
void displayPair(int grid, int arr[][MAX], int x1, int y1, int x2, int y2);

int main(){
	int diff, score, numScore, grid, userMenu;
	int arr[MAX][MAX], game[MAX][MAX];
	int arrScore[10];
	char namesArray[10][NMAX + 1];

	do{
		userMenu = getMenuChoice();
		switch(userMenu){
			case 0: 
			return 0;
			break;

			case 1: 
				printf("Enter difficulty (1, 2, or 3):");
				scanf("%d", &diff);
				grid = gameDifficulty(diff);
				fillGrid(diff);
				score = runGame(grid, arr);
				printf("Save score?\n1 - yes:");
				int scoreInput = 0;
				char tempVar;
				scanf("%d%c", &scoreInput, &tempVar);
			if(scoreInput == 1){
				//saveScore(score);
			}

			break;

			case 2:
				//numScore = readScores(arrScore, namesArray);
				printf("**HIGH SCORES**\n");
				for(int i = 0; i < numScore; i++){
					printf("%d - %s", arrScore[i], namesArray[i]);
				}
			break;
		}
	}while(userMenu > 0);

	return 0;
}

int getMenuChoice(){

	int menuChoice;
	printf("***MEMORY***\n1 - Play Game\n2 - Check Scores\n0 - EXIT\n\n");
	scanf("%d", &menuChoice);
	return menuChoice;
}

int runGame(int grid, int arr[][MAX]){
	int count;
	int score = grid * grid;
	int correct[MAX][MAX];
	for(int row = 0; row < grid; row++)
	{
		for(int col = 0; col < grid; col++)
		{
			correct[row][col] = 0;
		}
	}
	while(gameWon(grid,correct) == 0){
		displayBoard(grid, arr, correct);
		int row1, column1, row2, column2;
		userInput(grid, &row1, &column1);

		do{
			userInput(grid, &row2, &column2);
			if(row1 == row2 && column1 == column2){
				printf("Duplicate coordinates!\n");
			}
		}while(row1 == row2 && column1 == column2);

		count++;
	
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

		displayPair(grid, arr, row1, column1, row2, column2);

		if(checkMatch(grid, arr, row1, column1, row2, column2)){
			correct[row1][column1] = 1;
			correct[row2][column2] = 1;
			printf("MATCHED!\n");
			count--;
		}
		printf("\n");
	}

	displayBoard( grid, arr, correct);
	printf("YOU WON!!\n");
	score -= count;
	printf("%d points!\n", score);
	return score;
}

void displayBoard(int grid, int arr[][MAX], int correct[][MAX]){

	for(int r1 = 0; r1 < grid; r1++){
		for(int c1 = 0; c1 < grid; c1++){
			if(correct[r1][c1] == 1){
				printf("[%c]", arr[r1][c1]);
			}else{
				printf("[ ]");
			}
		}
		printf("\n");
	}
}

void userInput(int grid, int* row, int* column){

	int x, y;
	printf("Enter your coordinates from 1 to %d\n", grid);
	
	do{	
		scanf("%d %d", &x, &y);
		if(x > grid || y > grid)
		{
			printf("Please enter valid coordinates from 1 to %d\n", grid);
		}
	}while(x > grid || y > grid);

	*row = x -1;
	*column = y -1;
}

void displayPair(int grid, int arr[][MAX], int x1, int y1, int x2, int y2){
	
	for(int r1 = 0; r1 < grid; r1++){
		for(int c1 = 0; c1 < grid; c1++){
			if(x1 == r1 && y1 == c1){
				printf("[%c]", arr[r1][c1]);
			}
			else if(x2 == r1 && y2 == c1){
				printf("[%c]", arr[r1][c1]);
			}
			else
			{
				printf("[ ]");
			}
		}
	printf("\n");
	}
}

_Bool checkMatch(int grid, int arr[][MAX], int r1, int c1, int r2, int c2){

	if(arr[r1][c1] == arr[r2][c2]){
		return 1;
	}

	return 0;	
}

int gameDifficulty(int difficulty){

	int dimensions;
	if(difficulty == 1)
	{
		dimensions = difficulty*2;
	}
	else if(difficulty == 2)
	{
		dimensions = difficulty*2;
	}
	else if(difficulty == 3)
	{
		dimensions = difficulty*2;
	}
	return dimensions;
}

_Bool gameWon(int grid,  int correct[][MAX]){

	for(int r = 0; r < grid; r++){
		for(int c = 0; c < grid; c++){
			if(correct[r][c] == 0){
				return 0;
			}
		}
	}
	return 1;
}


//file writing code
//file saving code
//file reading code

void fillGrid(int difficulty){
	srand(time(NULL));
	int numPairs, numCards;
	int dimensions = difficulty*2;
	char matrix[dimensions][dimensions];
	char random = rand() % 18 + ' ';
	char array[numCards];

	
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
