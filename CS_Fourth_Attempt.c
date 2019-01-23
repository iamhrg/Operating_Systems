//This code is entitled to Harsh Gandhi.
//The following code shows the Fourth Attempt to solve the Critical Section Problem
//Starvation. One process can wait in it's non CS.

//Starvation and Livelock Problem

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include<unistd.h>

int want1=0,want2=0;
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
			want2=0;
			want2=1;
			//sleep(1);
			printf("Process 2 is waiting for entering in Critical Section!\n");
		}
		sleep(1);
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
			want1=0;
			want1=1;
			//sleep(1);
			printf("Process 1 is waiting for entering in Critical Section!\n");
		}
		sleep(1);
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
    pthread_t tid,tid1;
   	pthread_create(&tid, NULL, Process1,NULL);
    pthread_create(&tid1, NULL, Process2,NULL);
    pthread_exit(NULL);
    return 0;
}

