//Joshua Yi
//Project 5
//Dr. Atkinson
//5/13/14
//Tues. 2:15

#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "tree.h"
#include "pack.h"

typedef struct tree TREE;

void Insert(TREE *heap[257], int loc);
void pop(TREE *heap[257], int counter);
void DeleteMin(TREE *heap[257], int loc);
void binPrint(TREE *leaves[257], int count[257]);
void binCode(TREE *leaf, TREE *child);

int main(int argc,char *argv[])
{
	FILE *fp;
	int count[257];
    int c;
    int loc;
    int counter=0;
	TREE *leaves[257],*heap[257],*min1,*min2;
	assert(argc==3);
	//Initialize the arrays for the heap, leaves, and count.
	for(loc=0;loc<257;loc++)
	{
		heap[loc]=NULL;
		leaves[loc]=NULL;
		count[loc]=0;
	}
	fp=fopen(argv[1],"r");
	assert(fp!=NULL);
	//Input the characters
	while((c=getc(fp))!=EOF)
	{
		count[c]++;
	}
	//Copying the occurances of each character into the queue and copying trees into the queue matching each leaf slot
	for(loc=0;loc<256;loc++)
	{
		if(count[loc]!=0)
		{
			heap[counter]=createTree(count[loc],NULL,NULL);
			leaves[loc]=heap[counter];
			Insert(heap,counter++);
		}
	
	}
	heap[counter]=createTree(0,NULL,NULL);
	leaves[256]=heap[counter];
	Insert(heap,counter++);
	//Creating the tree with the bit codes
	while(counter>1)
	{
		min1=heap[0];
		pop(heap,--counter);
		min2=heap[0];
		pop(heap,--counter);
		heap[counter]=createTree(getData(min1)+getData(min2),min1,min2);
		Insert(heap,counter++);
	}
	binPrint(leaves,count);
	pack(argv[1],argv[2],leaves);
}

//Shift the queue after inserting a new leaf where the root will be the minimum
void Insert(TREE *heap[257], int loc)
{
	int parentloc;
	TREE *temp;
	parentloc=(loc-1)/2;
	if(heap[loc]!=heap[parentloc])
	{
        //If the heap location is smaller than the parent location.
		if(getData(heap[loc])<getData(heap[parentloc]))
		{
			temp=heap[parentloc];
			heap[parentloc]=heap[loc];
			heap[loc]=temp;
			Insert(heap,parentloc);
		}
	}
}

//Removing the root from the queue
void pop(TREE *heap[257], int counter)
{
	heap[0]=heap[counter];
	heap[counter]=NULL;
	DeleteMin(heap,0);
}

//This function arranges the queue after deleting the root
void DeleteMin(TREE *heap[257], int loc)
{
	int left;
    int right;
    int low;
	TREE *temp;
	left=2*loc+1;
	right=2*loc+2;
	if(heap[left]!=NULL)
	{
		if(heap[right]!=NULL)
		{
			if(getData(heap[left])<getData(heap[right]))
			{
				low=left;
			}
			else
			{
				low=right;
			}

			if(getData(heap[loc])>getData(heap[low]))
			{
				temp=heap[loc];
				heap[loc]=heap[low];
				heap[low]=temp;
				DeleteMin(heap,low);
			}
		}
		else
		{
			if(getData(heap[loc])>getData(heap[left]))
			{
				temp=heap[loc];
				heap[loc]=heap[left];
				heap[left]=temp;
				DeleteMin(heap,left);
			}	
		}
	}
}

//Prints each individual character, along with their count and binary code
void binPrint(TREE *leaves[257],int count[257])
{
	int loc;
	for(loc=0;loc<257;loc++)
	{
		if(leaves[loc]!=NULL)
		{
			if(isprint(loc))
			{
				printf("'%c' : %d ",loc,count[loc]);
			}
			else
			{
				if(loc<100)
				{
					printf("0%o : %d ",loc,count[loc]);
				}
				else
				{
					printf("%o : %d ",loc,count[loc]);
				}
			}
			binCode(leaves[loc],NULL);
			printf("\n");
		}
	}
}

//Prints the code of each character
void binCode(TREE *leaf, TREE *child)
{
	TREE *parent=getParent(leaf);
	if(parent==NULL)
	{
		if(child==NULL)
		{
			printf("0");
		}
		else if(child==getLeft(leaf))
		{
			printf("0");
		}
		else
		{
			printf("1");
		}
	}
	else
	{
		binCode(parent,leaf);
		if(child!=NULL)
		{
			if(child==getLeft(leaf))
			{
				printf("0");
			}
			else
			{
				printf("1");
			}
		}
	}
}
