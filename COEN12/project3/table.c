//Josh Yi
//Project 3
//Dr. Atkinson
//4/22/14
//Tues. 2:15

//This c file will implement a set abstract data type for strings. This program will utilize hashing to find elements in a hash table and will also insert elements into the hash table in order to output the amount of distinct words in the set.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include "set.h"

#define EMPTY 0
#define FILLED 1
#define DELETED 2

struct set {
	int count;
	int length;
	char **element;
	char *flags;
};

unsigned hashFunction(char *s);
int findElement(SET *sp, char *elt,bool *found);

//O(n)
//return a pointer to a new set with a maximum capacity of maxElts

SET *createSet(int maxElts) {
	SET *sp;
	int i;
	//allocating memory
	sp=malloc(sizeof(SET));
	assert(sp!=NULL);
	//setting the values and initializing the set pointers
	sp->count=0;
	sp->length=maxElts;
	sp->element=malloc(sizeof(char *)*maxElts);
	sp->flags=malloc(sizeof(char)*maxElts);
	assert(sp->element!=NULL && sp->flags!=NULL);
	//initialize each flag to EMPTY slot
	for(i=0;i<sp->length;i++) {
		sp->flags[i]=EMPTY;
	}
	return sp;
}

//O(n)
//deallocate memeory associated with the set pointed to by sp

void destroySet(SET *sp) {
	int i;
	assert(sp!=NULL);
	//only free the filled elements
	for(i=0;i<sp->length;i++) {
		if(sp->flags[i]==FILLED) {
			free(sp->element[i]);
		}
	}
	free(sp->flags);
	//free the whole set
	free(sp);
}

//O(1)
//return the number of elements in the set pointed to by sp

int numElements(SET *sp) {
	assert(sp!=NULL);
	return sp->count;
}

//O(1)/O(n)
//return whether elt is a member of the set pointed to by sp

bool hasElement(SET *sp, char *elt) {
	bool found;
	assert(sp!=NULL && elt!=NULL);
	findElement(sp,elt,&found);
	return found;
}

//O(1)/O(n)
//add elt to the set pointed to by sp. and return whether the set has changed

bool addElement(SET *sp, char *elt) {
	assert(sp!=NULL && elt!=NULL);
	bool found;
	int i;
	int position=findElement(sp,elt,&found);
	if(!found) {
	//if the element is not found, then allocate space and assign the element
	//also set the position to FILLED
		sp->element[position]=strdup(elt);
		sp->flags[position]=FILLED;
		sp->count++;
		return true;
	}
	else {
		return false;
	}
}

//O(1)/O(n)
//remove elt from the set pointed to by sp, and return whether the set changed

bool removeElement(SET *sp, char *elt) {
	assert(sp!=NULL && elt!=NULL);
	bool found;
	int i;
	int position=findElement(sp,elt,&found);
	if(found) {
		//freeing the space where the element is located and setting the flag to DELETED
		free(sp->element[position]);
		sp->flags[position]=DELETED;
		sp->count--;
		return true;
	}
	else {
		return false;	
	}
}

//O(n)
//hash function to assign the key to the element

unsigned hashString(char *s) {
	unsigned hash=0;
	while(*s!='\0')
		hash=31*hash+*s++;
	return hash;
}

//O(1)/O(n)
//return the location of an element in an array

int findElement(SET *sp, char *elt, bool *found) {
	int count=0;
	int deletedfirst=0;
	int tempposition=0;
	unsigned hashposition=hashString(elt);
	hashposition=hashposition%sp->length;
	while(count<sp->length) {
		//compare elements if the position is filled
		if(sp->flags[hashposition]==FILLED) {
			if(strcmp(sp->element[hashposition],elt)==0) {
				*found=true;
				return hashposition;
			}
		}
		//if the spot is empty then return the current position unless there was a deleted slot beforehand
		else if(sp->flags[hashposition]==EMPTY) {
			if(deletedfirst==1) {
				*found=false;
				return tempposition;
			}
			else {
				*found=false;
				return hashposition;
			}
		}
		//if the spot is deleted, check if there was a deleted slot before it.
		else if(sp->flags[hashposition]==DELETED) {
			if(deletedfirst==0) {
				tempposition=hashposition;
				deletedfirst=1;
			}
		}
		//increase hashposition and modulus it
		count++;
		hashposition++;
		hashposition=hashposition%sp->length;
	}
	*found=false;
	return hashposition;
}
