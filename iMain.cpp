#include "iGraphics.h"
#include "bitmap_loader.h"
#include <stdio.h>
#include <stdlib.h>


// user-defined headers
#include "gameBackground.h"
#include "gameMainMenuClicks.h"
#include "word.h"

// track mouse click
int globalMousePosX = 0, globalMousePosY = 0;

// animation position
int animatePosX = 800, animatePosY = 250;

// flag to decide actions for mouse click
char clickFlag[100] = "gameMenu";

// random word string
char random[50] = "random";
char newword[50];

// user input string
char userInput[100] = "";

// compare user input with random
void userInputCompare(){
	if(!strcmp(userInput, random)){
		strcpy(userInput, "");
		animatePosX = 800;
		getRandomWord(random);
	}
}


// decide value of flag
void flagDecision(int x, int y){
	
	//new game
	if((x >= 400 && x <=750) && (y >= 300 && y <= 400)) strcpy(clickFlag, "newGame");
	
	//leaderboard
	else if((x >= 350 && x <= 810) && (y >= 200 && y <= 300)) strcpy(clickFlag, "leaderboard");

	//exit
	else if((x >= 495 && x <= 695) && (y >= 100 && y <= 200)) strcpy(clickFlag, "exit");
}

// change x-axis value for word floating around
void changeX(){
	animatePosX -= 1; 
}


// word floating animation
void wordAnimation(char *word){
	if(animatePosX <= 800 && animatePosX >= 1){
		iSetColor(255, 213, 0);
		iText(animatePosX, animatePosY, random, GLUT_BITMAP_TIMES_ROMAN_24);
		int b = iSetTimer(20, changeX);
		iSetColor(255, 255, 255);
	}
	else if(animatePosX < 1) animatePosX = 800;
}

// call wordAnimation(char *word)
void showAnimation(){
	if(!strcmp(clickFlag, "newGame")) wordAnimation(random);
}

void iDraw()
{
	iClear();

	// background and other images
	showBackgroundFunctions(clickFlag);

	// take actions based on mouse click position
	clickFunctions(clickFlag);

	// decide flag value
	flagDecision(globalMousePosX, globalMousePosY);

	// shows word animation
	showAnimation();


	// verifying userInput value
	iText(5, 5, userInput, GLUT_BITMAP_TIMES_ROMAN_24);

	// compare userInput with random
	userInputCompare();
}

void iPassiveMouse(int x, int y)
{
	;
}


void iMouseMove(int mx, int my)
{
	;
}


void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		// globally declare mouse click position
		globalMousePosX = mx;
		globalMousePosY = my;
	}
}


void iKeyboard(unsigned char key)
{
	// add character at the end of userInput
	if(key == 'a') strcat(userInput, "a");
	if(key == 'b') strcat(userInput, "b");
	if(key == 'c') strcat(userInput, "c");
	if(key == 'd') strcat(userInput, "d");
	if(key == 'e') strcat(userInput, "e");
	if(key == 'f') strcat(userInput, "f");
	if(key == 'g') strcat(userInput, "g");
	if(key == 'h') strcat(userInput, "h");
	if(key == 'i') strcat(userInput, "i");
	if(key == 'j') strcat(userInput, "j");
	if(key == 'k') strcat(userInput, "k");
	if(key == 'l') strcat(userInput, "l");
	if(key == 'm') strcat(userInput, "m");
	if(key == 'n') strcat(userInput, "n");
	if(key == 'o') strcat(userInput, "o");
	if(key == 'p') strcat(userInput, "p");
	if(key == 'q') strcat(userInput, "q");
	if(key == 'r') strcat(userInput, "r");
	if(key == 's') strcat(userInput, "s");
	if(key == 't') strcat(userInput, "t");
	if(key == 'u') strcat(userInput, "u");
	if(key == 'v') strcat(userInput, "v");
	if(key == 'w') strcat(userInput, "w");
	if(key == 'x') strcat(userInput, "x");
	if(key == 'y') strcat(userInput, "y");
	if(key == 'z') strcat(userInput, "z");
}



void iSpecialKeyboard(unsigned char key)
{
	// exit program
	if (key == GLUT_KEY_END)
	{
		exit(0);
	}

	// change flag value to show game menu
	if(key == GLUT_KEY_HOME){
		strcpy(clickFlag, "gameMenu");
	}

	// shuffle random word and reset userInput
	if(key == GLUT_KEY_F1){
		strcpy(userInput, "");
		getRandomWord(newword);
		strcpy(random, newword);
	}
}

int main()
{
	
	iInitialize(1200, 700, "Typing Typhoon");
	iStart();

	return 0;
}