//Josh Yi
//Project 2
//Dr. Atkinson
//4/7/14
//Tues. 2:15

//This c file will implement a set abstract data type for strings. This program will utilize sequential search to find elements in the array and will also insert elements into a unsorted array in order to output the amount of distinct words in the set.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include "set.h"

struct set {
	int count;
	int length;
	char **element;
};

int findElement(SET *sp, char *elt);

//O(1)
//return a pointer to a new set with a maximum capacity of maxElts

SET *createSet(int maxElts) {
	SET *sp;
	//allocating memory
	sp=malloc(sizeof(SET));
	assert(sp!=NULL);
	//setting the values and initializing the set pointers
	sp->count=0;
	sp->length=maxElts;
	sp->element=malloc(sizeof(char *)*maxElts);
	assert(sp->element!=NULL);
	return sp;
}

//O(n)
//deallocate memeory associated with the set pointed to by sp

void destroySet(SET *sp) {
	int i;
	assert(sp!=NULL);
	for(i=0;i<sp->count;i++) {
		free(sp->element[i]);
	}
	//free the whole set
	free(sp);
}

//O(1)
//return the number of elements in the set pointed to by sp

int numElements(SET *sp) {
	assert(sp!=NULL);
	return sp->count;
}

//O(n)
//return whether elt is a member of the set pointed to by sp

bool hasElement(SET *sp, char *elt) {
	assert(sp!=NULL && elt!=NULL);
	int position;
	position=findElement(sp,elt);
	if(position>=0) {
		return true;
	}
	else {
		return false;
	}
}

//O(n)
//add elt to the set pointed to by sp. and return whether the set has changed

bool addElement(SET *sp, char *elt) {
	assert(sp!=NULL && elt!=NULL);
	int position;
	position=findElement(sp,elt);
	if(position>=0) {
		return false;
	}
	else {
		//allocating space and assigning the element at the end of the set
		sp->element[sp->count]=strdup(elt);
		assert(sp!=NULL);
		sp->count++;
		return true;
	}
}

//O(n)
//remove elt from the set pointed to by sp, and return whether the set changed

bool removeElement(SET *sp, char *elt) {
	assert(sp!=NULL && elt!=NULL);
	int position;
	position=findElement(sp,elt);
	if(position>=0) {
		//freeing the space where the element is located and moving the last element into that spot
		free(sp->element[position]);
		sp->element[position]=sp->element[(sp->count)-1];
		sp->count--;
		return true;
	}
	else {
		return false;	
	}
}

//O(n)
//return the location of an element in an array

int findElement(SET *sp, char *elt) {
	int i;
	//searching for the element
	for(i=0;i<sp->count;i++) {
		if(strcmp(sp->element[i],elt)==0) {
			return i;
		}
	}
	return -1;
}
