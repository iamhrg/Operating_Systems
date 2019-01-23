//This code is entitled to Harsh Gandhi.
//The following code is the implementation of the Lamport's Algorithm to solve the Critical Section Problem

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
int timestamp=0;
struct linked_list
{
	int time;
	char process;
	struct linked_list *next;
};

struct linked_list *frontp=NULL;
struct linked_list *rearp=NULL;
struct linked_list *frontq=NULL;
struct linked_list *rearq=NULL;


void Request(int data,char ch)
{
		if(rearp==NULL && frontp==NULL)
		{
			rearp=(struct linked_list *)malloc(sizeof(struct linked_list));
			rearp->time=data;
			rearp->process=ch;
			frontp=rearp;
			rearp->next=NULL;
		}
		else
		{
			rearp->next=(struct linked_list *)malloc(sizeof(struct linked_list));
			rearp=rearp->next;
			rearp->time=data;
			rearp->process=ch;
			rearp->next=NULL;
		}
		if(frontq==NULL && rearq==NULL)
		{
			rearq=(struct linked_list *)malloc(sizeof(struct linked_list));
			rearq->time=data;
			rearq->process=ch;
			frontq=rearq;
			rearq->next=NULL;
		}
		else
		{
			rearq->next=(struct linked_list *)malloc(sizeof(struct linked_list));
			rearq=rearq->next;
			rearq->time=data;
			rearq->process=ch;
			rearq->next=NULL;
		}
}

void Release()
{
	struct linked_list *temp;
	temp=frontp;
	if(frontp==rearp && frontp->next==NULL)
	{
		rearp=NULL;
		frontp=NULL;
	}
	else
		frontp=frontp->next;
	free(temp);
	struct linked_list *temp1;
	temp1=frontq;
	if(frontq==rearq && frontq->next==NULL)
	{
		rearq=NULL;
		frontq=NULL;
	}
	else
		frontq=frontq->next;
	free(temp1);
}

int Reply(char proc)
{
	if(proc=='p')
	{
		if(frontp->time==frontq->time && frontp->process==frontq->process && frontp->process=='p')
			return 1;
		else
			return 0;
	}
	else if(proc=='q')
	{
		if(frontp->time==frontq->time && frontp->process==frontq->process && frontp->process=='q')
			return 1;
		else
			return 0;
	}
	else
	{
		printf("Wrong Input!\n");
		exit(0);
	}
}

void *ProcessQ()
{
	while(1)
	{
		printf("Q is in Non Critical Section!\n");
		sleep(1);
		Request(timestamp++,'q');
		while(Reply('q')!=1)
		{
			printf("Q is waiting for entering in Critical Section!\n");
			sleep(1);
		}
		printf("Now Q is in Critical Section!\n");
		sleep(1);
		Release();
		printf("Finally Q is out of Critical Section!\n");
		
	}
	pthread_exit(NULL);
	
}

void *ProcessP()
{
	while(1)
	{
		printf("P is in Non Critical Section!\n");
		sleep(1);
		Request(timestamp++,'p');
		while(Reply('p')!=1)
		{
			printf("P is waiting for entering in Critical Section!\n");
			sleep(1);
		}
		printf("Now P is in Critical Section!\n");
		sleep(1);
		Release();
		printf("Finally P is out of Critical Section!\n");
		
	}
	pthread_exit(NULL);

}
  
int main(void)
{
	long int i;
    pthread_t tid,tid1;
   	pthread_create(&tid, NULL, ProcessQ,NULL);
    pthread_create(&tid, NULL, ProcessP,NULL);
    pthread_exit(NULL);
    return 0;
}

