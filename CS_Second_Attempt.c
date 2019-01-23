//This code is entitled to Harsh Gandhi.
//The following code shows the Second Attempt to solve the Critical Section Problem
//No Mutual Exclusion. Two processes can be in a CS at the same time.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include<unistd.h>
int want1=1,want2=1;
int count=0;
void *Process1()
{
	while(1)
	{
		printf("Process 1 is in Non Critical Section!\n"); //want1=0 NON CS, want1=1 CS
		sleep(1);
		while(want1!=1)
		{
			printf("Process 1 is waiting for entering in Critical Section!\n");
			sleep(1);
		}
		want2=0;
		printf("---------Now Process 1 is in Critical Section!\n");
		sleep(1);
		want2=1;
		//printf("Finally P is out of Critical Section!\n");
		sleep(1);
	

	}
	pthread_exit(NULL);
	
}

void *Process2()
{
		while(1)
	{
		printf("Process 2 is in Non Critical Section!\n"); //want2=0 Non CS, want2=1 CS
		sleep(1);
		while(want2!=1)
		{
			printf("Process 2 is waiting for entering in Critical Section!\n");
			sleep(1);
		}
		want1=0;
		printf("===========Now Process 2 is in Critical Section!\n");
		sleep(1);
		want1=1;
		//printf("Finally P is out of Critical Section!\n");
		sleep(1);
	

	}
	pthread_exit(NULL);
}
  
int main(void)
{
	//long int i;
    pthread_t tid,tid1;
   	pthread_create(&tid, NULL, Process1,NULL);
    pthread_create(&tid1, NULL, Process2,NULL);
    pthread_exit(NULL);
    return 0;
}

