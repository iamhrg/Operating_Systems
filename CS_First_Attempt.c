//This code is entitled to Harsh Gandhi.
//The following code shows the First Attempt to solve the Critical Section Problem
//Starvation. One process can wait in it's non CS.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
int turn=1;
int count=0;
void *process1()
{
	while(1)
	{	//printf("\n\n-------------------------------------\n");
		printf("--------------Process 2 is in Non Critical Section!\n");
		while(turn==2)
			{
			printf("Process 2 is waiting for entering in Critical Section!\n");
			 sleep(1);
			}
		printf("===========Now 2 is in Critical Section!\n"); //When turn=1, process 2 is executed
		printf("Finally 2 is out of Critical Section!\n");
		turn=2;

	}
		pthread_exit(NULL);
	
}

void *process2()
{
	while(1)
	{	//printf("\n\n-------------------------------------\n");
		printf("-------------Process 1 is in Non Critical Section!\n");
		while(turn==1)
			{printf("Process 1 is waiting for entering in Critical Section!\n");
			 sleep(1);
			}		
		printf("===============Now Process 1 is in Critical Section!\n");
		printf("Finally Process 1 is out of Critical Section!\n");
		count++;
		/*if(count==5)
			exit(1);
		*/
		turn=1;
			
	}
	pthread_exit(NULL);

}
  
int main(void)
{
	long int i;
    pthread_t tid,tid1;
   	pthread_create(&tid, NULL, process1,NULL);
    pthread_create(&tid, NULL, process2,NULL);
    pthread_exit(NULL);
    return 0;
}

