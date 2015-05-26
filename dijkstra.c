#include<stdio.h>
#include<stdio.h>
void dijkstra(int a[][10],int n,int source){
	int s[10],d[10],i,j,u=0,v=0,min;
	for(i=1;i<=n;i++){
		s[i]=0;
		d[i]=a[source][i];
	}
	s[source]=1;
	for(i=2;i<=n;i++){
		min=999;
		for(j=1;j<=n;j++){
			if(s[j]==0&&d[j]<min){
				min = d[j];
				u=j;
			}
		}
		s[u]=1;
		for(v=1;v<=n;v++){
			if(s[v]==0 && d[u]+a[u][v] < d[v] ){
				d[v]=a[u][v]+d[u];
			}
		}
	}
	for(i=1;i<=n;i++){
		if(i!=source)
			printf("\n%d->%d=%d",source,i,d[i]);
	}
}
int main(){
	int a[10][10], size, sum, i, j;
	printf("Enter the size: ");
	scanf("%d",&size);
	printf("Enter the matrix:\n");
	for(i=1;i<=size;i++){
		for(j=1;j<=size;j++){
			scanf("%d",&a[i][j]);
		}
	}
	dijkstra(a,size,1);	
}
/*
0 999 1 999
3 0 6 4
1 999 0 7
5 4 3 0

*/

