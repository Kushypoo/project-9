#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

_Bool checkMatch(int boardDimension, char board[][boardDimension], int r1, int r2, int c1, int c2);
int userScore(int userDifficulty);

int main(){
	
	int userDifficulty = 3;
	userScore(userDifficulty);

}

_Bool checkMatch(int boardDimension, char board[][boardDimension], int r1, int r2, int c1, int c2){
	_Bool match = 0;
	if(board[r1-1][c1-1] == board[r2-1][c2-1]){
		match = 1;
		return match;
	}else{
		return match;
	}
}

int userScore(int userDifficulty){
	int score = 2*(userDifficulty*userDifficulty);	
	if(!checkMatch){
		score--;
	}

}
