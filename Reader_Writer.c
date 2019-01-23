//This code is entitled to Harsh Gandhi.

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<semaphore.h>


int readers=0;
sem_t rmutex,resource;
int front=0;
int rear=0;
int Queue[10];
int n=0;
char proc='R';
void Enqueue(char ch)
{
	Queue[rear]=ch;
	rear=(rear+1)%10;
}

char Dequeue()
{
	int temp=front;
	front=(front+1)%10;
	return Queue[temp];
}

void *Reader()
{
	
	while(1)
	{
		//StartRead
		Enqueue('R');
		while(proc!='R')
		{
			printf("\n\n*********Reader is waiting.**********");
			sleep(1);
		}
		sem_wait(&rmutex);
		readers+=1;
		if(readers==1)
			sem_wait(&resource);
		sem_post(&rmutex);
		printf("\n _____________________________________________________\n|                                                     |\n|             Reader is reading the data.             |\n|_____________________________________________________|\n");
		sleep(1);
		proc=Dequeue();
		sleep(3);

		//End Read
		sem_wait(&rmutex);
		readers--;
				
		if(readers==0)
			sem_post(&resource);
		sem_post(&rmutex);
		//printf("\n\n..........Reader is leaving.........");
	}
}


void *Writer()
{
	//StarttWrite
	while(1)
	{
		sleep(3);
		Enqueue('W');
		while(proc!='W')
		{
			printf("\n\n*********Writer is waiting.**********");
			sleep(1);
		}
		sem_wait(&resource);
		
		printf("\n _____________________________________________________\n|                                                     |\n|             Writer is writing the data.             |\n|_____________________________________________________|\n");
		proc=Dequeue();
		sleep(1);
		printf("\n\n..........Writer is leaving.........");
		sem_post(&resource);

		sleep(3);
	}

}

int main()
{
    pthread_t tid1,tid2;
    sem_init(&rmutex,0,1);
    sem_init(&resource,0,1);
    pthread_create(&tid1, NULL, Reader, NULL);
    pthread_create(&tid2, NULL, Writer, NULL);
    pthread_exit(NULL);	
}

