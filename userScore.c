_Bool checkMatch(*/these ints are the board dimension, not user input*/ int boardDimension, char board[][boardDimension], int r1, int r2, int c1, int c2){
	_Bool match = false;
	if(board[r1-1][c1-1] == board[r2-1][c2-1]){
		match = true;
		return match;
	}else{
		return match;
	}
}

//need to keep this function running as long as the game is running in the main function.
int userScore(int userDifficulty){
	int score = 2*(userDifficulty*userDifficulty);	
	if(!checkMatch){
		score--;
	}

}
