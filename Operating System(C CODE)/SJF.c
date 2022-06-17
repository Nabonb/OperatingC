#include<stdio.h>
int main()
{
    int n=3;
    int bt[100]={24,3,3}, tt[100], p[100]= {1,2,3};
    int pos,temp;
    SJF (n, bt, p,pos,temp);
}
int SJF(int n, int bt[], int p[],int pos,int temp)
{

    for(int i=0; i<n; i++)
    {
        pos=i;
        for(int j=i+1; j<n; j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        }
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;

        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
    for (int i=0; i<n; i++)
    {
        printf("Process : %d ---------> ", p[i]);
        printf("Burst Time : %d\n", bt[i]);
    }
    Average(n, bt);

}
int Average(int n,int bt[])
{
    int wt[n];
    int tt[n];
    int sum=0;

    waiting(wt,bt, n);
    turnaround(wt,bt,n);

    for(int i=0; i<n; i++)
    {
        sum =wt[i]+ sum;
    }
    float avgwt=sum/(float)n;
    printf("Average Waiting Time Is: %.2f\n",avgwt);
}
int waiting(int wt[],int bt[], int n)
{
    wt[0]=0;
    printf("Waiting Time :\n");
    for(int i=1; i<n; i++)
    {
        wt[i]=bt[i-1]+ wt[i-1];
    }
    for(int i=0; i<n; i++)
    {
        printf("%d\n",wt[i]);
    }

}
int turnaround(int wt[],int bt[],int n)
{
    int tt[3];
    int sum =0;

    printf("Turn Around Time Is :\n");
    for(int i=0; i<n; i++)
    {
        tt[i]=wt[i]+bt[i];
        printf("%d\n",tt[i]);
    }
    for(int i=0; i<n; i++)
    {
        sum=tt[i]+sum;
    }
    float avgtt = sum/(float)n;
    printf("Average Turn Around Time Is : %.2f\n",avgtt);
}
