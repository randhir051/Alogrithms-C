#include<stdio.h>

int a[10][10],path[100],paths[10][10],dis[100],vis[100],visited[100],n,source,solno=0,j;
void distance(int a[10][10],int dist,int no,int s){
   int flag=0,i;
   for(i=1;i<=n;i++)
   {
       if(!visited[i])
       {
	  flag=1;
	  visited[i]=1;
	  path[no]=i;
	  distance(a,dist+a[s][i],no+1,i);
	  visited[i]=0;
	}
   }
   if(flag==0)
   {
      printf("\nSolution %d \n",solno);
      for(i=1;i<=n;i++)
      {
	 printf("%d->",path[i]);
	 paths[solno][i]=path[i];
      }
	
      printf("%d\t",source);
      printf("Distance:: %d\n",dist+a[s][source]);
      dis[solno]=dist+a[s][source];
      solno++;
   }
}

float optimal()
{
   int minm=dis[0],solnno=0,i;

   for(i=1;i<solno;i++)
   if( dis[i]<minm)
   {
      minm=dis[i];
      solnno=i;
   }
   printf("\nOptimal path is ");
   for(i=1;i<=n;i++)
   printf("%d->",paths[solnno][i]);
   printf("%d",source);
   printf("\nOptimal cost is %d",minm);
   return minm;
}

float nearest(){
   int i,j,x,y,cost=0,minm=999,count=0,f=1;
   printf("\n\nPath using nearest\n");
  printf("%d",source);
  vis[source]=1;
  while(count<n-1)
  {
    minm=999;

    for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
      {
        if(vis[i] && !vis[j] && a[i][j]<minm)
        {
          minm=a[i][j];
          if(f==1)
          {
            x=i;
            f=0;
          }
          y=j;
        }
      }

    cost=cost+a[x][y];
    printf("->%d",y);
    vis[y]=1;
    count++;
    x=y;
  } 

  printf("->%d",source);
  cost=cost+a[y][source];
  printf("\nMinimun cost is %d\n",cost);
  return cost;
}
void main()
{
   int dist=0,i,j;
   float p,q;
   printf("\nEnter the no of cities\n");
   scanf("%d",&n);
   printf("\nEnter\n");
   for(i=1;i<=n;i++)
   for(j=1;j<=n;j++)
   scanf("%d",&a[i][j]);
   printf("\nEnter the source node\n");
   scanf("%d",&source);
   visited[source]=1;
   path[1]=source;

   distance(a,dist,2,source);

   p=optimal();
   q=nearest();
   printf("\n\nResult=%f",(q/p));
 }
/*
0 3 1 5
3 0 6 4
1 6 0 7
5 4 7 0

*/


