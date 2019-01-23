//This code is entitled to Harsh Gandhi.

#include<stdio.h>
#include<stdlib.h>

struct Process
{
	int val;
	int Burst,Waiting,TurnAround,Queue,Arrival,Response,CT;
};

typedef struct Process P;
void Sorting(int n,P List[])
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(List[i].Arrival>List[j].Arrival)
			{
				P temp=List[i];
				List[i]=List[j];
				List[j]=temp;
			}
		}
	}
			
}

int main()
{
	int num,Qnum;
	int BT=0,TAT=0,WT=0,time=0,RT=0;
	
	//Input
	printf("\nEnter Number of Processes: ");
	scanf("%d",&num);
	P List[num+1];
	
	printf("\nNow Enter the Number of Queues: ");
	scanf("%d",&Qnum);
	
	int i;
	for(i=0;i<num;i++)
	{
		List[i].val=0;
		printf("\n\nNow enter for every process:\n");
		printf("\n\tArrival time for P[%d]: ",i+1);
		scanf("%d",&List[i].Arrival);
		printf("\n\tBurst time for P[%d]: ",i+1);
		scanf("%d",&List[i].Burst);
		BT+=List[i].Burst;
		printf("\n\tQueue Number for P[%d]: ",i+1);
		scanf("%d",&List[i].Queue);
	}
	
	//Sorting	
	Sorting(num,List);
	List[num].Queue=9999;
	
	//Main Logic
	printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\tRT\n\n");
	for(time=List[0].Arrival;time<BT;)
	{
		int min=num;
		for(i=0;i<num;i++)
		{
			if(List[i].Arrival<=time  && List[i].val==0 && List[i].Queue<List[min].Queue)
				min=i;
		}
		List[min].val=1;
		List[min].Response=time-List[min].Arrival;
		time+=List[min].Burst;
		List[min].CT=time;
		List[min].TurnAround=List[min].CT-List[min].Arrival;
		List[min].Waiting=List[min].TurnAround-List[min].Burst;
		
		RT+=List[min].Response;
		WT+=List[min].Waiting;
		TAT+=List[min].TurnAround;
		
		printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",min+1,List[min].Arrival,List[min].Burst,List[min].CT,List[min].TurnAround,List[min].Waiting,List[min].Response);
	}
	
	printf("\n\n\tAverage Response Time: %0.1f\n", (RT*1.0)/num);
	printf("\tAverage Waiting Time: %0.1f\n", (WT*1.0)/num);
    printf("\tAverage Turnaround Time: %0.1f\n\n", (TAT*1.0)/num);
	
	
	return 0;
}
