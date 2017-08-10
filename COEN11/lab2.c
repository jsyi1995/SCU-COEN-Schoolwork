#include <stdio.h>
#include <string.h>

struct restaurant {
	int numarray;
	char namearray[20];
};
struct restaurant entry[10];

int counter=0;

void insert(char person[],int num) {
	int i;
	struct restaurant *pointer=entry;
	pointer=entry;
	if(counter==10) {
		printf("Comeback back later.\n");
	}
	else {
		for(i=0;i<counter;i++) {
			if(strcmp(person,pointer->namearray)==0) {
				printf("Name is already taken. Try Again.\n");
				return;
			}
			pointer++;
		}
		pointer=entry;
		for(i=0;i<counter;i++) {
			if(pointer->namearray=='\0') {
				strcpy(pointer->namearray,person);
				counter++;
				pointer->numarray=num;
				break;
			}
			pointer++;
		}
	}
	pointer=entry;
}

void delete(int number) {
	int i;
	struct restaurant *pointer;
	pointer=entry;
	if(counter==0) {
		printf("No tables are reserved.\n");
	}
	else {
		int flag=0;
		for(i=0;i<counter;i++,pointer++) {
			if(pointer->numarray==number) {
				printf("You have successfully removed the name %s with %d people or person.\n",pointer->namearray,pointer->numarray);
				flag=1;
				break;
			}
		}
		if(flag==0) {
			printf("There is no table with that size.\n");
		}
		for(;i<counter;i++,pointer++) {
				pointer->numarray=pointer+1->numarray;
				strcpy(pointer->namearray,pointer+1->namearray);
		}
		counter--;
	}
}

void list(void) {
	int i;
	struct restaurant *pointer=entry;
	pointer=entry;
	if(counter==0) {
		printf("No tables are reserved.\n");
	}
	else {
		for(i=0;i<counter;i++) {
			if(pointer->namearray!='\0') {
				printf("Table %d is used by %s with %d people or person.\n",i+1,pointer->namearray,pointer->numarray);
			}
			pointer++;
		}
	}
	pointer=entry;
}

int main(void) {
	int response;
	int size;
	int temp=0;
	char name[20];
	while(1) {
		printf("Welcome to the Restaurant Waiting List Program!\n");
		printf("Type 1 to add name and number of people to a table.\n");
		printf("Type 2 to remove the oldest entry which fits the size of the table specified.\n");
		printf("Type 3 to list info.\n");
		printf("Type anything else to quit.\n");
		scanf("%d",&response);
		switch(response) {
			case 1:
				printf("Enter in your name:\n");
				scanf("%s",name);
				printf("Enter in number of people:\n");
				scanf("%d",&size);
				insert(name,size);
				break;
			case 2:
				printf("Enter in a table size.\n");
				scanf("%d",&temp);
				delete(temp);
				break;
			case 3:
				list();
				break;
			default:
				return 0;
		}
	}
	return 0;
}
