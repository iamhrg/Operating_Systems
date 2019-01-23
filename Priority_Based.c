//This code is entitled to Harsh Gandhi.
//The following code shows the practical implementation of the Priority based Process Scheduling Algorithm

#include<stdio.h>
#include<stdlib.h>
struct processes
{
      char processes_name;
      int arrival, burst, ct, wait, turnaround, pr;
      int status;
} ob[10],swap;
 
int totalno; //Maximum number of processes-Global
 
int main()
{
      int i,j,time=0, burst=0,large;
      int c;
      float wait = 0, turnaround = 0, avg_wait, avg_turnaround;
      printf("\nEnter Total Number of processes:\t");
      scanf("%d", &totalno);
      for(i = 0, c = 1; i < totalno; i++, c++)
      {
            ob[i].processes_name = c;
            printf("\nEnter the details for processes[%d]:\n", ob[i].processes_name);
            printf("Enter the Arrival Time:\t");
            scanf("%d", &ob[i].arrival );
            printf("Enter the burst time:\t");
            scanf("%d", &ob[i].burst);
            printf("Enter the priority:\t");
            scanf("%d", &ob[i].pr);
            ob[i].status = 0;			//Status
            burst = burst + ob[i].burst; //Total Burst Time
      }
      for(i = 0; i < totalno - 1; i++)			//To sort the Arrival Time.
      {
            for(j=i+1;j<totalno;j++)
            {
                  if(ob[i].arrival>ob[j].arrival)
                  {
                        swap=ob[i];
                        ob[i]=ob[j];
                        ob[j]=swap;
                  }
            }
      }
      ob[9].pr = -9999;
      printf("\nProcesses Name\tArrival Time\tBurst Time\tPriority\tWaiting Time");
      printf("\n--------------\t------------\t----------\t--------\t------------\n\n");
      for(time = ob[0].arrival; time < burst;)
      {
            large = 9;
            for(i = 0; i < totalno; i++)
            {
                  if(ob[i].arrival <= time && ob[i].status != 1 && ob[i].pr > ob[large].pr) 
                  {
                        large = i;
                  }
            }
            time=time+ob[large].burst;
            ob[large].ct=time;
            ob[large].wait = ob[large].ct - ob[large].arrival - ob[large].burst; //Waitingtime = Completion Time - Arrivaltime - BurstTime
            ob[large].turnaround = ob[large].ct - ob[large].arrival; //Turnaround = Completiontime - arrivaltime
            ob[large].status = 1;
            wait = wait + ob[large].wait; //Total waiting time
            turnaround = turnaround + ob[large].turnaround; //Total Turnaround Time
            printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", ob[large].processes_name, ob[large].arrival, ob[large].burst, ob[large].pr, ob[large].wait);
      }
      avg_wait = wait / totalno; //Average Waiting time
      avg_turnaround = turnaround / totalno; //Average Turn Around time
      printf("\n\n");
      printf("Average waiting time   :\t%f\n", avg_wait);
      printf("Average Turnaround Time:\t%f\n", avg_turnaround);
      return 0;
}
