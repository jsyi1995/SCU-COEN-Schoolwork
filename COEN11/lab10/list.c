//Joshua Yi
//Lab 10
//Prof. Figuiera
//Wed 2:15
//3/12/14
#include "global.h"

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