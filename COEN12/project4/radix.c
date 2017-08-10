//Josh Yi
//Project 4
//Dr. Atkinson
//5/13/14
//Tues. 2:15

//This program will take a sequence of integers and output it into sorted order with radix sorting.

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "deque.h"

#define r 10

int max;

DEQUE *sort(DEQUE *dp);
void print(DEQUE *dp);

//The main function of the program.
int main(void)
{
	DEQUE *dp;
	dp=createDeque();
	int input;
	//Taking in the input values.
	while(scanf("%d",&input)==1)
	{
		if(input<0)
		{
			printf("The input is invalid, it must be positive integer.\n");
		}
        else
        {
            addLast(dp,input);
            if(input>max)
            {
                max=input;
            }
		}
    }
    sort(dp);
	print(dp);
    destroyDeque(dp);
	return 1;
}

//This function will sort the integers into ascending order.
DEQUE *sort(DEQUE *dp)
{
	DEQUE *queue[r];
	int temp;
	int i,j;
	int loc,power,digit;
	assert(dp!=NULL);
	digit=ceil(log(max+1)/log(r));
	//Initializing the deques.
	for(i=0;i<r;i++)
	{
		queue[i]=createDeque();
	}
	//Using the mod of the integer to sort.
	for(i=1;i<=digit;i++)
	{
		//Sorting the integers based on current significant digit.
		while(numItems(dp)>0)
		{
            temp=removeFirst(dp);
            power=(pow(r,i));
			loc=temp%power/(pow(r,i-1));
            addLast(queue[loc],temp);
		}
		//Move all integers into the main queue.
		for(j=0;j<r;j++)
		{
			while(numItems(queue[j])>0)
			{
				addLast(dp,removeFirst(queue[j]));
			}
		}
	}
	return dp;
}

//This function will print out the sorted integers.
void print(DEQUE *dp)
{
	assert(dp!=NULL);
	while(numItems(dp)>0)
	{
		printf("%d\n",removeFirst(dp));
	}
}
