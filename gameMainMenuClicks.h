#ifndef GAMEMAINMENUCLICKS_H
#define GAMEMAINMENUCLICKS_H

#include <iostream>

// start new game
void newGame(char* flag){
	if(!(strcmp(flag, "newGame"))){
		int newGameScreen = iLoadImage("images\\background.png");
		iShowImage(0, 0, 1200, 700, newGameScreen);
	}
}

// show leaderboard
void leaderboard(char* flag){
	if(!(strcmp(flag, "leaderboard"))){
		int leaderboardSample = iLoadImage("images\\leaderboardSample.png");
		iShowImage(0, 0, 1200, 700, leaderboardSample);
	}
}

// exit game
void exitGame(char* flag){
	if(!(strcmp(flag, "exit"))){
		exit(0);
	}
}


// call all functions
void clickFunctions(char* flag){
	newGame(flag);
	leaderboard(flag);
	exitGame(flag);
}

#endif