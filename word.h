#ifndef WORD_H
#define WORD_H

#include <string.h>


// word structure
typedef struct word{
    char wordBody[50]; // word body
    int wordLength; // word length

	// empty constructor
    word(){
        ;
        }

	// paramterized constructor
    word(char* wordBody){
        strcpy(this->wordBody, wordBody);
        }
    
	// set word body
    void set_WordBody(char* wordBody){
        strcpy(this->wordBody, wordBody);
        }

	// return word body
    char* get_WordBody(){
        return wordBody;
        }

	// return word length
    int get_WordLength(){
        return strlen(wordBody);
        }
    } Word;

	// return random word
	void getRandomWord(char* wordnew){
		FILE *wordListAll = fopen("wordListBin.bin", "rb");
		Word listWords[10000];
    
		for(int i=0;i<10000;i++)
		fread(&listWords[i], sizeof(Word), 1, wordListAll);
    
		fclose(wordListAll);

		strcpy(wordnew, listWords[rand()%10000].get_WordBody());
}

#endif