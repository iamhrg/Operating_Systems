//This code is entitled to Harsh Gandhi.
//The following code shows the practical implementation of the Shortest Job First based Process Scheduling Algorithm

#include<stdio.h>

int main()
	{
	 int no;
	 float total=0;
	 float wait,response,turnaround;
	 wait=0; response=0; turnaround=0;
	 int burst[30],processes[30],waittime[30],responsetime[30],turnaroundtime[30];
	 printf("\n Enter the number of processes: ");
	 scanf("%d", &no);
	 int i;
	 printf("Enter the Burst time for all processes: \n");
	 for(i=0;i<no;i++)
	 	{
	 	printf("For process %d : ",i+1);
	  	scanf("%d",&burst[i]); processes[i]=i+1;
	 	}
	 int j,loc,swap;
	 for(i=0;i<no;i++)
	 	{ 
	 	 loc=i;
	 	 for(j=i+1;j<no;j++)
	 	 	if(burst[j]<burst[loc])
	 	 		loc=j;
	 	 swap=burst[i];
	 	 burst[i]=burst[loc];
	 	 burst[loc]=swap;
	 	 swap=processes[i];
	 	 processes[i]=processes[loc];
	 	 processes[loc]=swap;
	 	 }
	 for(i=0;i<no;i++)
	 	{
	 	waittime[i]=responsetime[i]=turnaroundtime[i]=0;
	 	}
	   for(i=1;i<no;i++)
      {
            waittime[i]=0;
            for(j=0; j<i;j++)
                 waittime[i]=waittime[i]+burst[j];
             
            total=total+waittime[i];
      }
	 	wait= total/no;
	 	total=0;
	 	printf("\nProcess ID\tBurst Time\tWaiting Time\tResponse Time\tTurnaround Time");
	 	printf("\n----------\t----------\t------------\t-------------\t----------------");
	 	for(i =0;i<no; i++)
      {
            turnaroundtime[i] = burst[i] + waittime[i];
            total = total + turnaroundtime[i];
            printf("\nProcess[%d]\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i], burst[i], waittime[i],waittime[i],turnaroundtime[i]);
      }
      turnaround=total / no;
      printf("\n\nAverage Response Time:\t%f",wait);
      printf("\n----------------------");
      printf("\nAverage Waiting Time:\t%f", wait);
      printf("\n---------------------");
      printf("\n\nAverage Turnaround Time:%f", turnaround);
      printf("\n-----------------------\n\n");
      return 0;
     }
