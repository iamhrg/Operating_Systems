//This code is entitled to Harsh Gandhi.
//The following code shows the practical implementation of the Round Robin Process Scheduling Algorithm

#include<stdio.h>
#include<stdlib.h>

struct processes
{ int pno;
  int arrivaltime;
  int executiontime;
  int waitingtime;
  int tet;
  int t;
  int tt;
 }ob[30];
 
int main()
 { int no,ch;
  printf("Enter the number of processes: ");
  scanf("%d ",&no);
  
  int i,k,j;
  for(i=0;i<no;i++)
  	{printf("Enter the burst time for the processes: ");
  	 scanf("%d ",&ob[i].executiontime);
     ob[i].tet=ob[i].executiontime;
     ob[i].arrivaltime=ob[i].t=ob[i].tt=ob[i].waitingtime=0;
     ob[i].pno=i+1;
     }
   printf("Enter the quantum: 1 or 2 ");
   scanf("%d ",&ch);
   int totaltime=0;
   for(i=0;i<no;i++)
      totaltime+=ob[i].executiontime;
    i=0;
    k=0;
    int rrg[99];
    for(j=0;j<totaltime;j++)
    {
        if((k==0)&&(ob[i].executiontime!=0))
        {
            ob[i].waitingtime=j;
            if((ob[i].t!=0))
            {
                ob[i].waitingtime-=ch*ob[i].t;
            }
        }
        if((ob[i].executiontime!=0)&&(k!=ch))
        {
            rrg[j]=ob[i].pno;
            ob[i].executiontime-=1;
            k++;
        }
        else
        {
            if((k==ch)&&(ob[i].executiontime!=0))
            {
                ob[i].t+=1;
            }
            i=i+1;
            if(i==no)
            {
                i=0;
            }
 
                k=0;
            j=j-1;
        }
    }
 
 
    int twt=0;
    int ttt=0;
    printf("\n Result Of Round Robin");
    printf("\n PNo\tET\tWT\tTT");
    for(i=0;i<no;i++)
    {
        ob[i].tt=ob[i].waitingtime+ob[i].tet;
        ttt+=ob[i].tt;
        twt+=ob[i].waitingtime;
        printf("\n %d \t %d \t %d \t %d",ob[i].pno,ob[i].tet,ob[i].waitingtime,ob[i].tt);
    }
 
    printf("\n Average Waiting Time: %f",(float)twt/no);
    printf("\n Average Turn Around Time: %f",(float)ttt/no);
 
return 0;
}

