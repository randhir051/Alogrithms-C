#include<stdio.h>
struct edge {
	int begv, endv, cost;
};
typedef struct edge E;
E e[10],temp;
int count=0,p[100],parenti,parentj,nedges=0,sum=0;
int getparent(int p[],int v){
	while(p[v]!=-1)
		v = p[v];
	return v;
}
int main(){
	int n, a[10][10],i,j;
	printf("Enter the number of vertices: ");
	scanf("%d",&n);
	printf("\nEnter the cost matrix:\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j]!=0&&a[i][j]!=999){
				count++;
				e[count].begv=i;
				e[count].endv=j;
				e[count].cost=a[i][j];
			}
		}
	}

	for(i=1;i<count;i++){
		for(j=i+1;j<=count;j++){
			if(e[i].cost > e[j].cost){
				temp.cost = e[i].cost;
				temp.endv = e[i].endv;
				temp.begv = e[i].begv;
				e[i].cost = e[j].cost;
				e[i].begv = e[j].begv;
				e[i].endv = e[j].endv;
				e[j].cost = temp.cost;
				e[j].endv = temp.endv;
				e[j].begv = temp.begv;
			}
		}
	}
	for(i=1;i<=count;i++){0 
		p[i]=-1;
	}
	for(i=1;i<=count;i++){
		parenti = getparent(p,e[i].begv);
		parentj = getparent(p,e[i].endv);
		if(parenti!=parentj){
			printf("%d->%d=%d\n",e[i].begv,e[i].endv,e[i].cost);
			sum+=e[i].cost;
			p[parentj]=parenti;
			nedges++;
		}
	}
	if(nedges==n-1){
		printf("Cost is : %d\n",sum);
	}
}
