#ifndef GAMEBACKGROUND_H
#define GAMEBACKGROUND_H


// main background
void showBackground(){
	int background = iLoadImage("images\\background.png");
	iShowImage(0, 0, 1200, 700, background);
}


// title icon
void showTitle(){
	int title = iLoadImage("images\\typingTyphoon.png");
	iShowImage(200, 450, 800, 220, title);
}


// new game icon
void showNewGame(){
	int newGame = iLoadImage("images\\newGame.png");
	iShowImage(400, 300, 350, 100, newGame);
}


// leaderboard icon
void showLeaderboard(){
	int leaderboard = iLoadImage("images\\leaderboard.png");
	iShowImage(350, 200, 460, 100, leaderboard);
}


// exit icon
void showExit(){
	int showExitButton = iLoadImage("images\\exit.png");
	iShowImage(495, 100, 200, 100, showExitButton);
}


// show all background functions
void showBackgroundFunctions(char* flag){
	if(!strcmp(flag, "gameMenu")){
	showBackground();
	showTitle();
	showNewGame();
	showLeaderboard();
	showExit();
	}
}

#endif