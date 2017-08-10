//Josh Yi
//Project 4
//Dr. Atkinson
//5/6/14
//Tues. 2:15

//This c file is a deque abstract data type that utilizes a circular doubly linked list using a sentinel node.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deque.h"

typedef struct node {
	int data;
	struct node *next;
	struct node *prev;
}NODE;

struct deque {
	int count;
	struct node *head;
};

//O(1)
//creating the deque
DEQUE *createDeque(void) {
	DEQUE *dp;
	dp=malloc(sizeof(DEQUE));
	dp->count=0;
	dp->head=malloc(sizeof(NODE));
	dp->head->next=dp->head;
	dp->head->prev=dp->head;
	return dp;
}

//O(n)
//destroying the deque
void destroyDeque(DEQUE *dp) {
	NODE *np1,*np2;
	assert(dp!=NULL);
	np1=dp->head->next;
	while(np1!=dp->head) {
		np2=np1;
		np1=np1->next;
		free(np2);
	}
	free(dp->head);
	free(dp);
}

//O(1)
//returning the number of items in the deque
int numItems(DEQUE *dp) {
	assert(dp!=NULL);
	return dp->count;	
}

//O(1)
//adding x as the first item in the deque
void addFirst(DEQUE *dp, int x) {
	assert(dp!=NULL);
	NODE *np;
	NODE *dummy;
	dummy=dp->head;
	np=malloc(sizeof(NODE));
	np->data=x;
	dp->count++;
	np->next=dummy->next;
	np->prev=dummy;
	dummy->next->prev=np;
	dummy->next=np;
}

//O(1)
//adding x as the last item in the deque
void addLast(DEQUE *dp, int x) {
	assert(dp!=NULL);
	NODE *np;
	NODE *dummy;
	dummy=dp->head;
	np=malloc(sizeof(NODE));
	np->data=x;
	dp->count++;
	np->next=dummy;
	np->prev=dummy->prev;
	dummy->prev->next=np;
	dummy->prev=np;
}

//O(1)
//removing and returning the first item in the deque
int removeFirst(DEQUE *dp) {
	assert(dp!=NULL);
	int temp=0;
	NODE *np;
	NODE *dummy;
	dummy=dp->head;
	dp->count--;
	np=dummy->next;
	dummy->next=dummy->next->next;
	np->next->prev=dummy;
	temp=np->data;
	free(np);
	return temp;
}

//O(1)
//removing and returning the last item in the deque
int removeLast(DEQUE *dp) {
	assert(dp!=NULL);
	int temp=0;
	NODE *np;
	NODE *dummy;
	dummy=dp->head;
	dp->count--;
	np=dummy->prev;
	dummy->prev=dummy->prev->prev;
	np->prev->next=dummy;
	temp=np->data;
	free(np);
	return temp;
}

//O(1)
//returning the first item in the deque
int getFirst(DEQUE *dp) {
	assert(dp!=NULL);
	return dp->head->next->data;
}

//O(1)
//returning the last item in the deque
int getLast(DEQUE *dp) {
	assert(dp!=NULL);
	return dp->head->prev->data;
}
