#include <stdio.h>
#include <string.h>

typedef union {
	char school[20];
	float salary;
	int retire;
} infounion;

struct infostruct{
	char namearray[20];
	int age;
	infounion status;
} ;

struct infostruct array[10];
int counter=0;

void insert(char person[]) {
	int tempage=0;
	char tempschool[20];
	float tempsalary;
	int retireyear;
	if(counter>9) {
		printf("List is full.\n");
		return;
	}
	printf("Enter in the age:\n");
	scanf("%d",&tempage);
	if (tempage<=21) {
		printf("Enter in the name of school:\n");
		scanf("%s",tempschool);
		strcpy(array[counter].status.school,tempschool);
	}
	else if (tempage>21 && tempage<65) {
		printf("Enter in the salary per month:\n");
		scanf("%f",&tempsalary);
		array[counter].status.salary = tempsalary;
	}
	else if (tempage>=65) {
		printf("Enter in the years of retirement:\n");
		scanf("%d",&retireyear);
		array[counter].status.retire = retireyear;
	}
	strcpy(array[counter].namearray,person);	
	array[counter].age = tempage;
	counter++;
}

void delete(char temp[]) {
	int i;
	if(counter==0) {
		printf("No names are reserved.\n");
	}
	else {
		int flag=0;
		for(i=0;i<counter;i++) {
			if(strcmp(array[i].namearray,temp)==0) {
				printf("You have successfully removed the name %s in slot %d.\n",array[i].namearray,i+1);
				array[i]=array[counter-1];
				flag=1;
				break;
			}
		}
		if(flag==0) {
			printf("There is no name in database that you  entered.\n");
		}
		counter--;
	}
}

void show(void) {
	int i;
	if(counter==0) {
		printf("No names are reserved.\n");
	}
	else {
		for(i=0;i<counter;i++) {
			printf("Slot %d\n",i+1);
			printf("Name: %s\n",array[i].namearray);
			printf("Age: %d\n",array[i].age);
			if (array[i].age<=21) {
				 printf("School: %s\n",array[i].status.school);
			}
			else if (array[i].age>21 && array[i].age<65) {
				printf("Salary per month: %f\n",array[i].status.salary);
			}
			else if (array[i].age>=65) {
				printf("Years of retirement: %d\n",array[i].status.retire);
			}
		}
	}
}

int main(void) {
	int response=0;
	char temp[20];
	char name[20];
	while(1) {
		printf("Welcome to the People List Program!\n");
		printf("Type 1 to add info of someone.\n");
		printf("Type 2 to remove the info of someone.\n");
		printf("Type 3 to list info.\n");
		printf("Type anything else to quit.\n");
		scanf("%d",&response);
		switch(response) {
			case 1:
				printf("Enter in a name to insert:\n");
				scanf("%s",name);
				insert(name);
				break;
			case 2:
				printf("Enter in a name to delete:\n");
				scanf("%s",temp);
				delete(temp);
				break;
			case 3:
				show();
				break;
			default:
				return 0;
		}
	}
	return 0;
}
