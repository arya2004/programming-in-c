#include<stdio.h>
#define MAX 9999;
struct Process
{
    int no,AT,BT,CT,WT,TAT,Priority,Status;
};
struct Process Input(int i)
{
    struct Process p;
    printf("\nProcessess No: %d\n",i);
    p.no=i;
    printf("Enter Arrival Time: ");
    scanf("%d",&p.AT);
    printf("Enter Burst Time: ");
    scanf("%d",&p.BT);
    printf("Enter Priorityority: ");
    scanf("%d",&p.Priority);
    p.Status=0;
    return p;
}

void main()
{
    int n,s,CT=0,remaining;
    struct Process p[10],temp;
    float avgTAT=0,avgWT=0;
    printf("<--Priority Scheduling Algorithm Non-Preemptive\n");
    printf("Enter Number of Processesses: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        p[i]=Input(i+1);
    }
        
    for(int i=0;i<n-1;i++){

        for(int j=0;j<n-i-1;j++) {

            if(p[j].AT>p[j+1].AT)
            {
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }   
    }
        
            
    p[9].Priority=MAX;
    remaining=n;
    printf("\nProcessessNo\tAT\tBT\tPri\tCT\tTAT\tWT\tRT\n");
    for(CT=p[0].AT;remaining!=0;)
    {
        s=9;
        for(int i=0;i<n;i++){
            
            if(p[i].AT<=CT && p[i].Status!=1 && p[i].Priority<p[s].Priority){
                 s=i; 
            }
               
        }
            
        p[s].CT=CT=CT+p[s].BT;
        p[s].TAT=p[s].CT-p[s].AT;
        avgTAT+=p[s].TAT;
        p[s].WT=p[s].TAT-p[s].BT;
        avgWT+=p[s].WT;
        p[s].Status=1;
        remaining--;
        printf("P%d\t\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[s].no,p[s].AT,p[s].BT,p[s].Priority,p[s].CT,p[s].TAT,p[s].WT,p[s].WT);
    }
    avgTAT/=n,avgWT/=n;
    printf("\nAverage TurnAroundTime=%f\nAverage WaitingTime=%f",avgTAT,avgWT);
}