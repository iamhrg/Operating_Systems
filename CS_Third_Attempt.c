//This code is entitled to Harsh Gandhi.
//The following code shows the Third Attempt to solve the Critical Section Problem
//Deadlock Problem

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include<unistd.h>
int want1=0,want2=0;  //1 for CS, 0 for NON CS
int count=0;
void *Process1()
{
	while(1)
	{
		printf("Process 2 is in Non Critical Section!\n");
		sleep(1);
		want2=1;
		while(want1==1)
		{
			printf("------Process 2 is waiting for entering in Critical Section!\n");
			sleep(1);
		}
		printf("Now Process 2 is in Critical Section!\n");
		sleep(1);
		printf("Finally Process 2 is out of Critical Section!\n");
		sleep(1);
		want2=0;

	}
	pthread_exit(NULL);
	
}

void *Process2()
{
	while(1)
	{
		printf("Process 1 is in Non Critical Section!\n");
		sleep(1);
		want1=1;
		while(want2==1)
		{
			printf("==========Process 1 is waiting for entering in Critical Section!\n");
			sleep(1);
		}
		printf("Now Process 1 is in Critical Section!\n");
		sleep(1);
		printf("Finally Process 1 is out of Critical Section!\n");
		sleep(1);
		want1=0;
			
	}
	pthread_exit(NULL);

}
  
int main(void)
{
	long int i;
    pthread_t tid,tid1;
   	pthread_create(&tid, NULL, Process1,NULL);
    pthread_create(&tid1, NULL, Process2,NULL);
    pthread_exit(NULL);
    return 0;
}

