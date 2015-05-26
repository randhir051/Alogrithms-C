#include<stdio.h>
int prims(int a[][10],int n,int source){
	int s[10],d[10],intermediate[10],i,j,sum=0,u=0,v=0,min;
	for(i=1;i<=n;i++){
		s[i]=0;
		d[i]=a[source][i];
		intermediate[i]=source;
	}
	s[source]=1;
	for(i=1;i<=n;i++){		
		min=999;
		for(j=1;j<n;j++){
			if(s[j]==0&&d[j]<min){
				min = d[j];
				u=j;
			}
		}		
		sum+=d[u];
		s[u]=1;
		for(v=1;v<=n;v++){
			if(s[v]==0 && d[v]>a[u][v]){
				d[v]=a[u][v];
				intermediate[v]=u;
			}
		}
	}
	if(sum<999){
		printf("Edges selected for MST: ");
	}
	for(i=1;i<=n;i++){
		if(i!=source){
			printf("\nEdge %d->%d=%d",intermediate[i],i,d[i]);
		}
	}
	return sum;
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
	sum = prims(a,size,1);
	if(sum<999){
		printf("\nSpanning tree exists! weight = %d",sum);
	}else{
		printf("\nSpanning tree dosent exist!");
	}
}


















