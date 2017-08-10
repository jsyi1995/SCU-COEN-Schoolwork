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

#define NODE struct node

struct node {
	char name[20];
	int number;
	NODE *next;
};

extern NODE *head;
extern NODE *tail;

void read_file();
void insertParty();
void deleteParty();
void listParty();
void write_file();
void quit();
void *auto_save(void *arg);
void temp_file(char *tempfile);

extern pthread_mutex_t mutex;


