//Joshua Yi
//Lab 6
//Wednesday 2:15 PM
//2/12/14
//Prof. Figueira
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NODE struct node

struct node
{
        char name[20];
        int number;
        NODE *next;
};

NODE *head[4];
NODE *tail[4];

void insert(void);
void search(void);
void list(void);
void quit(void);

int main(void)
{
		int i;
		for (i=0;i<4;i++) 
		{
			head[i]=NULL;
			tail[i]=NULL;
		}
		int option;
		while(1)
		{
        	printf("Type '0' to enter in customer and table size, '1' to search for table size, '2' for show list, or anything else to quit.\n");
			scanf("%d",&option);
        	switch(option)
			{
				case 0:
                	insert();
					break;
				case 1:
                	search();
					break;
				case 2:
                	list();
					break;
				default:
                	quit();
					return 0;
        	}
		}
}

void insert(void)
{
		int i;
		int organize;
        char name_enter[20];
        int number_enter;
		printf("Please enter name and table size:\n");
        scanf("%s",name_enter);
		scanf("%d",&number_enter);
        NODE *p;
		NODE *q;
		//determining the list where the values will be stored
		if(number_enter>0 && number_enter<=2)
		{
			organize=0;
		}
		else if(number_enter>=3 && number_enter<=4)
		{
			organize=1;
		}
		else if(number_enter>=5 && number_enter<=6)
		{
			organize=2;
		}
		else if(number_enter>=7)
		{
			organize=3;
		}
		//check if a name is already taken
		for(i=0;i<4;i++)
		{
			q=head[i];
        	while (q!=NULL)
        	{
                if(strcmp(name_enter,q->name)==0)
                {
                        printf("Name is already in the list, please try again.\n");
                        return;
                }
                q=q->next;
			}
        }
		//check if memory is available
		p=(NODE *)malloc(sizeof(NODE));
		if(p==NULL)
        {
        	printf("No more memory!!!\n");
			return;
        }
        strcpy(p->name,name_enter);
        p->number=number_enter;
		//if list is empty
        if(head[organize]==NULL)
		{
			head[organize]=p;
			tail[organize]=p;
			p->next=NULL;
		}
		//if there is at least one node
		else
		{
			tail[organize]->next=p;
			p->next=NULL;
			tail[organize]=p;
		}
}

void search(void)
{
		NODE *p;
		NODE *q;
		int seat;
		int organize;
        printf("Please enter seats available\n");
        scanf("%d",&seat);
		//determining the list where the values will be stored
       	if (seat>0 && seat<=2)
		{
			organize=0;
		}
		else if (seat>=3 && seat<=4)
		{
			organize=1;
		}
		else if (seat>=5 && seat <=6)
		{
			organize=2;
		}
		else if (seat>=7)
		{
			organize=3;
		}
		p=q=head[organize];
		while (p!=NULL)
		{
			if (seat>=p->number)
			{
				printf("Assigning table to %s\n",p->name);
				//deleting the node from a list
				if(p==head[organize])
				{
					head[organize]=p->next;
					if (head[organize]==tail[organize])
					{
						tail[organize]=(NODE*)NULL;
					}
				}
				else if(p==tail[organize])
				{
					tail[organize]=q;
					q->next=(NODE*)NULL;
				}
				else
				{
					q->next=p->next;
				}
				free(p);
				return;
			}
			q=p;
			p=p->next;
		}
		printf("No match has been found!!!\n");
}

void list(void)
{
	NODE *p;
	//output the values from each list
	int i;
	for(i=0;i<4;i++)
	{
		if(head[i]!=NULL)
		{
			p=head[i];
			while(p!=NULL)
			{
        		printf("%s %d\n",p->name,p->number);
            	p=p->next;
       		}
		}
		else
		{   
			printf("There are no names in list %d\n",i+1);
		}
    }
}

void quit(void)
{
	//freeing every single node
	int i;
	NODE *p;
	NODE *q;
	for(i=0;i<4;i++)
	{
		p=q=head[i];
		while(p!=NULL)
		{
			p=p->next;
			free(q);
			q=p;
		}
	}
}
