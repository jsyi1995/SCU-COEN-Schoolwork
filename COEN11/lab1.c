#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int division(int x, int y, int z) {
	if((x/y)==z) {
		return 1;
	}
	else {
		return 0;
	}
}

int main(void) {
	srand((int)time(NULL));
	printf("Division Program\n");
	int i;
	int dividend;
	int divisor;
	int quotient;
	int answer;
	int percent;
	int result;
	int counter=0;
	for(i=0;i<10;i++) {
		quotient=rand()%12;
		divisor=rand()%12+1;
		dividend=quotient*divisor;
		printf("%d / %d = ", dividend, divisor);
		scanf("%d", &answer);
		result=division(dividend,divisor,answer);
		if(result==1) {
			counter++;
			printf("Correct!\n");
		}
		else {
			printf("Incorrect!\n");
			printf("Correct answer is %d\n", quotient);
		}
	}
	percent=counter*10;
	printf("You have gotten %d percent correct!\n", percent);
	return 0;
}
