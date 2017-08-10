//Joshua Yi
//Lab 10
//Prof. Figuiera
//Wed 2:15
//3/12/14
#include "global.h"

#define NODE struct node

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
