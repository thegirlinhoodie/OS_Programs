#include<stdio.h>
typedef struct Process
{
  int pid;
  int at;
  int bt;
  int ct;
  int tt;
  int wt;
  int rt;
  int fin;
  int remtime;
  int alenq;
}Pro;

void roundrobin(Pro[],int,int);
int tp[100],pt[100],k=-1,j=-1;
void main()
{
  int n,tq;
  printf("Enter no. of processes\n");
  scanf("%d",&n);
  Pro p[n];
  for(int i=0;i<n;i++)
    {
      printf("Process %d\n",i+1);
      printf("Enter at\n");
      scanf("%d",&p[i].at);
      printf("Enter bt\n");
      scanf("%d",&p[i].bt);
      p[i].ct=0;
      p[i].wt=0;
      p[i].tt=0;
      p[i].pid=i+1;
      p[i].remtime=p[i].bt;
      p[i].fin=0;
      p[i].alenq=0;
    }
  printf("Enter time quatum\n");
  scanf("%d",&tq);
  for(int i=0;i<n-1;i++)
    {
      for(j=0;j<n-i-1;j++)
        {
          if(p[j].at>p[j+1].at)
          {
            Pro temp=p[j];
            p[j]=p[j+1];
            p[j+1]=temp;
          }
        }
    }
  roundrobin(p,n,tq);
}
void roundrobin(Pro p[],int n,int tq)
{
  int f=0,r=0,cr=0;
  int q[n+1];
  for(int i=0;i<n+1;i++)
    q[i]=-1;
  q[cr]=cr;
  p[cr].alenq=1;
  int ttt=0,twt=0,trt=0;
  float att=0,art=0,awt=0;
  int el=0,finpro=n;
  tp[++j]=0;
  while(finpro)
    {
      if(p[cr].fin)
      {
        cr=(cr+1)%n;
        continue;
      }
      if(p[cr].at>el)
      {
        el=el+(p[cr].at-el);
        pt[++k]=0;
        tp[++j]=el;
      }
      if(p[cr].remtime==p[cr].bt)
       p[cr].rt=el-p[cr].at;
      p[cr].remtime-=tq;
      el+=tq;
      if(p[cr].remtime<0)
      {
        el+=p[cr].remtime;
        p[cr].remtime=0;
      }
      pt[++k]=p[cr].pid;
      tp[++j]=el;
      if(p[cr].remtime==0)
      {
        p[cr].ct=el;
        p[cr].tt=p[cr].ct-p[cr].at;
        p[cr].wt=p[cr].tt-p[cr].bt;
        p[cr].fin=1;
        finpro--;
      }
      for(int i=0;i<n;i++)
        {
          if(p[i].remtime==p[i].bt && p[i].at<=el && !p[i].alenq)
          {
            r=(r+1)%(n+1);
            q[r]=i;
            p[i].alenq=1;
          }
        }
      if(p[cr].remtime!=0)
      {
        r=(r+1)%(n+1);
        q[r]=cr;
      }
      q[f]=-1;
      f=(f+1)%(n+1);
      cr=q[f];
      if(cr==-1)
      {
        int idletime=el;
        int np=-1;
        for(int i=0;i<n;i++)
          {
            if(!p[i].fin && p[i].at>el )
            {
              if(np==-1 || p[i].at<p[np].at)
              {
                np=i;
              }
            }
          }
        if(np!=-1)
        {
          el=p[np].at;
          pt[++k]=0;
          tp[++j]=el;
          r=0;
          f=0;
          q[r]=np;
          cr=q[f];
        }   
      }
    }
  for(int i=0;i<n-1;i++)
    {
      for(int j=0;j<n-i-1;j++)
        {
          if(p[j].pid>p[j+1].pid)
          {
            Pro temp=p[j];
            p[j]=p[j+1];
            p[j+1]=temp;
          }
        }
    }
  printf("Observation table\n");
  printf("Pid\tAT\tBT\tCT\tTT\tWT\tRT\n");
  for(int i=0;i<n;i++)
    {
      printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tt,p[i].wt,p[i].rt);
      ttt+=p[i].tt;
      trt+=p[i].rt;
      twt+=p[i].wt;
    }
  att=(float)ttt/n;
  awt=(float)twt/n;
  art=(float)trt/n;
  printf("Avg TT: %.2f\n",att);
  printf("Avg RT: %.2f\n",art);
  printf("Avg WT: %.2f\n",awt);
  printf("Gannt chat(p0->idle time\n");
  for(int i=0;i<=k;i++)
    printf("| P%d\t",pt[i]);
  printf("|\n");
  for(int i=0;i<=j;i++)
    printf("%d\t",tp[i]);
  printf("\n");
}