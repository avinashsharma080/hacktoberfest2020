#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int count=0;
int partition(int a[],int low,int high)
{ 	int pi,i,j,temp;
	i=low;
	j=high;
	pi=low;
	while(i<j)
	{
		while(a[i]<=a[pi]&&i<high)
		{
		i++;
		count++;
	    }
		while(a[j]>a[pi])
		{
		j--;
		count++;
	    }
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	temp=a[pi];
	a[pi]=a[j];
	a[j]=temp;
	return j;
}

void quick_sort(int a[],int low,int high)
{
	int i,j;
	if(low<high)
	{
		j=partition(a,low,high);
		quick_sort(a,low,j-1);
        quick_sort(a,j+1,high);
	}
}

int main()
{
	int *a,n,i;
     clock_t time_req;
	printf("Enter the number of elements:");
	scanf("%d",&n);
	a=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	a[i]=rand()%100;
   time_req=clock();
	quick_sort(a,0,n-1);
	time_req=clock() - time_req;
   printf("\nArray after sorting:");
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
	printf("\n NUMBER OF SWAPSt= %d",count);
   printf("\nTime taken: %f",(float)time_req/CLOCKS_PER_SEC );
	return 0;
}
