#include <stdio.h>

void swap(int *a,int *b)
{
    int temp = *a;
    *a=*b;
    *b=temp;
}

void sort(int *pid,int *at,int *bt,int n)
{
    for(int i = 0;i<n;i++)
    {
        for(int j = 0 ;j<n;j++)
        {
            if(at[i]<at[j])
            {
            swap(&at[i],&at[j]);
            swap(&bt[i],&bt[j]);
            swap(&pid[i],&pid[j]);
            }
        }
    }
}

int main()
{
    int n;
     printf("Enter the number of processes: ");
    scanf("%d", &n);

    int at[n],bt[n],pid[n];
    int a,b;
    for(int i = 0 ;i<n;i++)
    {
        printf("Enter the arrival time and burst time : \n");
        scanf("%d%d",&a,&b);
        at[i]=a;
        bt[i]=b;
        pid[i]=pid[i+1];
    }
    sort(pid,at,bt,n);
    int ct[n],tat[n],wt[n];
    for(int i = 0;i<n;i++)
    {
        if(i==0)
        {
            ct[i] = at[i]+bt[i];
        }
        else
        {
            ct[i]=ct[i-1]+bt[i];
        }
        tat[i]=ct[i]-at[i];
        wt[i]= tat[i]-bt[i];
    }

    for(int i = 0 ;i<n;i++)
    {
        printf("pid : %d \t at : %d \t bt : %d \t ct : %d \t tat :%d \t wt:%d \t \n",i,at[i],bt[i],ct[i],tat[i],wt[i]);
    }

    float avg_tat,avg_wt;
    for(int i = 0;i<n;i++)
    {
        avg_tat += tat[i];
        avg_wt +=wt[i];
    }
    avg_tat = avg_tat/n;
    avg_wt = avg_wt/n;
    printf("average tat : %f",avg_tat);
    printf("average wt : %f",avg_wt);
}
