//Josh Yi
//Project 6
//Dr. Atkinson
//6/3/14
//Tues. 2:15

//This C++ file is a deque abstract data type that utilizes a circular doubly linked list using a sentinel node.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deque.h"

struct Node {
	int data;
	struct Node *next;
	struct Node *prev;
};

//O(1)
//creating the deque
Deque::Deque() {
	count=0;
	head=new Node;
	head->next=head;
	head->prev=head;
}

//O(n)
//destroying the deque
Deque::~Deque() {
	Node *np1,*np2;
	np1=head->next;
	while(np1!=head) {
		np2=np1;
		np1=np1->next;
		delete np2;
	}
}

//O(1)
//returning the number of items in the deque
int Deque::size() {
	return count;
}

//O(1)
//adding x as the first item in the deque
void Deque::addFirst(int x) {
    Node *np=new Node;
	Node *dummy=head;
	np->data=x;
	count++;
	np->next=dummy->next;
	np->prev=dummy;
	dummy->next->prev=np;
	dummy->next=np;
}

//O(1)
//adding x as the last item in the deque
void Deque::addLast(int x) {
	Node *np=new Node;
	Node *dummy=head;
	np->data=x;
	count++;
	np->next=dummy;
	np->prev=dummy->prev;
	dummy->prev->next=np;
	dummy->prev=np;
}

//O(1)
//removing and returning the first item in the deque
int Deque::removeFirst() {
    assert(count>0);
	int temp=0;
	Node *np;
	Node *dummy=head;
	count--;
	np=dummy->next;
	dummy->next=dummy->next->next;
	np->next->prev=dummy;
	temp=np->data;
	delete np;
	return temp;
}

//O(1)
//removing and returning the last item in the deque
int Deque::removeLast() {
    assert(count>0);
	int temp=0;
	Node *np;
	Node *dummy=head;
	count--;
	np=dummy->prev;
	dummy->prev=dummy->prev->prev;
	np->prev->next=dummy;
	temp=np->data;
	delete np;
	return temp;
}

//O(1)
//returning the first item in the deque
int Deque::getFirst() {
	return head->next->data;
}

//O(1)
//returning the last item in the deque
int Deque::getLast() {
	return head->prev->data;
}
