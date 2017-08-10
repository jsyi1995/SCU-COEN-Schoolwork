//Joshua Yi
//Lab 10
//Prof. Figuiera
//Wed 2:15
//3/12/14
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "global.h"

#define NODE struct node

NODE *head=(NODE*)NULL;
NODE *tail=(NODE*)NULL;

void read_file();
void insertParty();
void deleteParty();
void listParty();
void write_file();
void quit();
void *auto_save(void *arg);
void temp_file(char *tempfile);

pthread_mutex_t mutex;

int main(int argc, char *argv[]) {
	int response;
	int size;
	int temp=0;
	char name[20];
	//if file name is missing
	if(argc!=3) {
		printf("Name of the file is missing!\n");
		return 1;
	}
	else {
		read_file(argv[1]);
	}
	//initializing pthread and autosaver
	pthread_t mythread;
	pthread_mutex_init (&mutex, NULL);
	pthread_create(&mythread, NULL, auto_save, (void *) argv[2]);
	while(1) {
		printf("Welcome to the Restaurant Waiting List Program!\n");
		printf("Type 1 to add name and number of people to a table.\n");
		printf("Type 2 to search and delete the oldest entry.\n");
		printf("Type 3 to list info.\n");
		printf("Type 4 to read auto-save.\n");
		printf("Type anything else to quit.\n");
		scanf("%d",&response);
		switch(response) {
			case 1:
				printf("Enter in your name:\n");
				scanf("%s",name);
				printf("Enter in number of people:\n");
				scanf("%d",&size);
				pthread_mutex_lock(&mutex);
				insertParty(name,size);
				pthread_mutex_unlock(&mutex);
				break;
			case 2:
				
				printf("Enter in a table size.\n");
				scanf("%d",&temp);
				pthread_mutex_lock(&mutex);
				deleteParty(temp);
				pthread_mutex_unlock(&mutex);
				break;
			case 3:
				listParty();
				break;
			case 4:
				pthread_mutex_lock(&mutex);
				temp_file(argv[2]);
				pthread_mutex_unlock(&mutex);
				break;
			default:
				write_file(argv[1]);
				pthread_mutex_lock(&mutex);
				pthread_cancel(mythread);
				pthread_mutex_unlock(&mutex);
				pthread_mutex_destroy(&mutex);
				quit();
				return 0;
		}
	}
	return 0;
}
