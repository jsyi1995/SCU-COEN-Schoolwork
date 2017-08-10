//Josh Yi
//Project 2
//Dr. Atkinson
//4/13/14
//Tues. 2:15

//This c file will implement a set abstract data type for strings. This program will utilize binary search to find the elements in an array and will also insert elements into a sorted array in order to output the amount of distinct words in the set.

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

int findElement(SET *sp, char *elt,bool *found);

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
	free(sp->element);
	//free the whole set
	free(sp);
}

//O(1)
//return the number of elements in the set pointed to by sp

int numElements(SET *sp) {
	assert(sp!=NULL);
	return sp->count;
}

//O(logn)
//return whether elt is a member of the set pointed to by sp

bool hasElement (SET *sp, char *elt) {
	bool found;
	assert(sp!=NULL && elt!=NULL);
	findElement(sp,elt,&found);
	return found;
}

//O(n)
//add elt to the set pointed to by sp. and return whether the set has changed

bool addElement(SET *sp, char *elt) {
	assert(sp!=NULL && elt!=NULL);
	bool found;
	int i;
	int position=findElement(sp,elt,&found);
	if(!found) {
		//shifting right to left until insert location and then allocating space and assigning the element
		for(i=sp->count-1;i>=position;i--) {
			sp->element[i+1]=sp->element[i];
		}
		sp->element[position]=strdup(elt);
		sp->count++;
		return true;
	}
	else {
		return false;
	}
}

//O(n)
//remove elt from the set pointed to by sp, and return whether the set changed

bool removeElement(SET *sp, char *elt) {
	assert(sp!=NULL && elt!=NULL);
	bool found;
	int i;
	int position=findElement(sp,elt,&found);
	if(found) {
		//freeing the space where the element is located and shifting left to right until last spot
		free(sp->element[position]);
		for(i=position;i<sp->count;i++) {
			sp->element[i]=sp->element[i+1];		
		}
		sp->count--;
		return true;
	}
	else {
		return false;	
	}
}

//O(logn)
//return the location of an element in an array

int findElement(SET *sp, char *elt, bool *found) {
	int lo,mid,hi,diff;
	lo=0;
	hi=sp->count-1;
	//cuts the items its searching in half until it finds the element
	while(lo<=hi) {
		mid=(lo+hi)/2;
		diff=strcmp(elt,sp->element[mid]);
		if(diff<0) {
			hi=mid-1;
		}
		else if(diff>0) {
			lo=mid+1;
		}
		else {
			*found=true;
			return mid;
		}
	}
	*found=false;
	return lo;
}
