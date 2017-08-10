//Joshua Yi
//Lab 9
//Prof. Figuiera
//Wed 2:15
//3/5/14
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

void read_file(char *customerlist) {
	FILE *fp;
	char name[20];
	int number;
	fp=fopen(customerlist,"r");
	//if there are permissions or the file does not exist
	if(fp==NULL) {
		printf("Unable to read the file.\n");
		return;
	}
	else {
		//scan for two arguments, name and number
		fseek(fp,43,SEEK_SET);
		while(fscanf(fp,"%s %d",name,&number)==2) {
			pthread_mutex_lock (&mutex);
			insertParty(name,number);
			pthread_mutex_unlock (&mutex);
		}
	}
	fclose(fp);
	return;
}

void insertParty(char *person,int num) {
	NODE *p,*q;
	//check is memory is availible
	if((p=(NODE*)malloc(sizeof(NODE)))==(NODE*)NULL) {
		printf("Not enough memory.\n");
	}
	q=head;
	//check if a name is already inserted
	while(q!=NULL) {
		if(strcmp(person,q->name)==0) {
			printf("Name already entered.\n");
			return;
		}
		q=q->next;
	}
	strcpy(p->name,person);
	p->number=num;
	//when list contains no nodes
	if(head==NULL) {
		head=p;
		tail=p;
		p->next=NULL;
	}
	//when list contains at least one node
	else {
		tail->next=p;
		p->next=NULL;
		tail=p;
	}
}

void deleteParty(int num) {
	NODE *p,*q;
	int flag=0;
	p=q=head;
	//if list is empty
	if(head==NULL) {
		printf("List is empty.\n");
		return;
	}
	//if only one node is present
	if(head->next==NULL) {
		if(head->number<=num) {
			printf("Table with %d people by %s has been found,\n",num,p->name);
			head=tail=NULL;
			flag=1;
		}
	}
	//if there is more than one node
	else {
		while(p!=NULL) {
			if(p->number<=num) {
				flag=0;
				break;
			}
			q=p;
			p=p->next;
		}
		if(p==head) {
			head=p->next;
			printf("Table with %d people by %s has been found,\n",num,p->name);
		}
		else if(p==tail) {
			tail=q;
			tail->next=NULL;
			printf("Table with %d people by %s has been found,\n",num,p->name);
		}
		else {
			q->next=p->next;
			free(p);
			printf("Table with %d people by %s has been found,\n",num,p->name);
			return;
		}
	}
	if(flag==0) {
		printf("No table has been found.\n");
	}
}

void listParty(void) {
	NODE *p;
	p=head;
	//check if list is empty
	if(head==NULL) {
		printf("No names are reserved.\n");
		return;
	}
	else {
		while(p!=NULL) {
			printf("%s %d\n",p->name,p->number);
			p=p->next;
		}
	}
}

void write_file(char *customerlist) {
	FILE *fp;
	NODE *p;
	fp=fopen(customerlist,"w");
	//If file doesnt not exist for writing.
	if(fp==NULL) {
		printf("Unable to write into the file.\n");
		return;
	}
	//write into text file
	else {
		fprintf(fp,"Name\tGroup Size\n");
		fprintf(fp,"--------------------------\n");
		p=head;
		while(p!=NULL) {
			fprintf(fp,"%s\t%d\n",p->name,p->number);
			p=p->next;
		}
	}
	fclose(fp);
	return;
}

void *auto_save(void *arg) {
	char *tempfile=(char*)arg;
	//every five seconds, write data into binary file
	FILE *fp;
	NODE *p;
	while(1) {
		pthread_mutex_lock (&mutex);
		p=head;
		fp=fopen(tempfile,"wb");
		if(fp==NULL)
		{
			printf("Autosaving error...\n");
		}
		printf("Autosaving...\n");
		while(p!=NULL)
		{
   			fwrite(p,sizeof(NODE),1,fp);
   			p=p->next;
		}
		fclose(fp);
		pthread_mutex_unlock (&mutex);
		sleep(5);
	}
	return 0;
}

void temp_file(char *tempfile)
{
	FILE *fp;
    NODE *p;
    int r;
    fp=fopen(tempfile,"rb");
	//checking if binfile exists
    if(fp==NULL)
    {
    	printf("Unable to read the save file.\n");
    }
    else
    {
  		p=(NODE *) malloc (sizeof(NODE));
   		if(p==NULL)
   		{
       		printf("Unable to access the autosave file.\n");
       		return;
   		}
		//reading the binary file
        while((r=fread(p,sizeof(NODE),1,fp))>0)
        {
            printf("%s %d\n",p->name,p->number);
        }
        free(p);
    }
	fclose(fp);
    return;
}

void quit() {
	//freeing every single node
	NODE *p;
	NODE *q;
	p=q=head;
	while(p!=NULL) {
		p=p->next;
		free(q);
		q=p;
	}
}

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
