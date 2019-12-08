#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	srand(time(NULL));
}

char randomCharGenerator(void){
	
	int rand = (rand() % 33) + '!';
	return (char)rand;
}

void createBoard(int userDifficulty, char board[][]){
	
	int boardSize, pairNum;
	boardSize = userDifficulty*userDifficulty;
	pairNum = boardSize/2;
	char charArray[pairNum];
	

	for(int i = 0; i < userDifficulty; i++){
		for(int j = 0; j < userDifficulty; j++){
			board[i][j] = charArray[j];
		}
	}
}
