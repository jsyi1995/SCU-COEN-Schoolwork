//Joshua Yi
//Lab 8
//Prof. Figueira
//Wed 2:15
//2/26/14
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(char [],int,int);

int main(int argc,char *argv[])
{
	char buffer[100];
	int size;
	FILE *fp1, *fp2;
	//Check if filenames are present.
	if(argc!=3)
	{
		printf("The names of the files are missing.\n");
		return 0;
	}
	//Open the files in order to read and write.
	fp1=fopen(argv[1],"r");
	fp2=fopen(argv[2],"w");
	//Check if the read file is empty.
	if (fp1==NULL)
	{
		printf("Unable to read or write to the files.\n");
		fclose(fp1);
		fclose(fp2);
		return 0;
	}
	//Begin the reverse function then write the strings into the file.
	while(fgets(buffer,100,fp1)!=NULL)
	{
			size=strlen(buffer); 
			reverse(buffer,0,size-2);
			fprintf(fp2,"%s",buffer);
	}
	printf("File strings have successfully reversed.\n");
	fclose(fp1);
	fclose(fp2);
	return 0;
}

void reverse(char *str, int index, int size)
{
	char temp;
	//Check if the index is equal to or greater than size
	if(index>=size) {
		return;
	}
	//Reversing strings by swapping the positions
	temp=*(str+index);
	*(str+index)=*(str+size);
	*(str+size)=temp;
	reverse(str,index+1,size-1);
}
