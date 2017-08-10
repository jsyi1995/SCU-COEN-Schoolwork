//Josh Yi
//Project 1
//Dr. Atkinson
//3/31/14
//Tues. 2:15

//This program will read words from a text file and display the total number of words.

#include <stdio.h>
#include <string.h>
#define MAX_WORD_LENGTH 30

int main(int argc, char *argv[]) {
	char word[MAX_WORD_LENGTH+1];
	int counter=0;
	//checking if information for the file exists
	if(argc!=2) {
		printf("Unable to find the file information.\n");
		return 0;
	}
	FILE *fp;
	fp=fopen(argv[1],"r");
	//if there are permissions or the file does not exist
	if(fp==NULL) {
		printf("Unable to read the file.\n");
		return 0;
	}
	else {
		//scan the text and retrieve the words into a buffer and count the number of words
		while(fscanf(fp,"%s",word)==1) {
			counter++;
		}
	}
	fclose(fp);
	printf("%d total words\n",counter);
	return 0;
}
