#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<omp.h>
int total=0;
void merge(int A[], int low, int mid, int high){
	int k = 0,*c=NULL;
	c = (int*) malloc((high-low +2)*sizeof(int));
	if(c==NULL){
		printf("Sorry!");
	}
	int i = low, j = mid+1;
	while(i<=mid && j<=high){
		if(A[i]<A[j]){
			c[k]=A[i];k++;i++;
		}else{
			c[k]=A[j];k++;j++;
		}
	}
	while(i<=mid){
		c[k]=A[i];k++;i++;
	}
	while(j<=high){
		c[k]=A[j];k++;j++;
	}
	j=0;
	for(i=low;i<=high;i++){
		A[i]=c[j];
		j++;
	}
	free(c);
}
void mergesort(int A[],int low, int high){
	int mid;
	float nthreads,tid;
	#pragma omp parallel shared(A,low,high,mid,nthreads,tid)
	{
		if(low<high)
		#pragma omp sections nowait
		{	
			mid = (low + high)/2;
			mergesort(A,low,mid);
			mergesort(A,mid+1,high);
			merge(A,low,mid,high);		
		}
	}
	tid = omp_get_thread_num();
	if(tid==0){
		nthreads = omp_get_num_threads();
		total+=nthreads;
	}
}


int main(){
	int *A,size,i;
	printf("Enter the size: ");
	scanf("%d",&size);
	A = (int*) malloc(size*sizeof(int));
	for(i=0;i<size;i++){
		A[i]=random();
	}
	mergesort(A,0,size-1);
	printf("\n%d\n",total);
}
