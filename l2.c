#include<stdio.h>
#include<sys/time.h>
#include<stdlib.h>

int a[5000];

int partition(int l,int h)
{
	int temp,i,j;
	int pivot=a[l];
	i=l;
	j=h;
	while(i<=j)
	{
		while(a[i] <=pivot && i<=h)
			i++;
		while(a[j]>pivot && j>=l)
			j--;
		if(i < j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
		else
		{
			temp=a[l];
			a[l]=a[j];
			a[j]=temp;
		}
	}
	return j;
}

void quick_sort(int l,int h)
{
	if(l<h)
	{
		int j=partition(l,h);
		quick_sort(l,j-1);
		quick_sort(j+1,h);
	}
}
int main()
{
	struct timeval start,end;
	int no,i=0,j=0,ele=0;
	FILE *fp=fopen("lab2_2.txt","w");
	printf("\n ENTER THE no of iteration");
	scanf("%d",&no);
	for(i=0;i<no;i++)
	{
		printf("\n ENter the no of element");
		scanf("%d",&ele);
		for(j=0;j<ele;j++)
		{
			a[j]=rand()%100;
			printf(" %d ",a[j]);
		}
		
	
		gettimeofday(&start,NULL);
		quick_sort(0,ele-1);
		gettimeofday(&end,NULL);
		printf("\n after sorting::");
		for(j=0;j<ele;j++)
		{
			printf(" %d ",a[j]);
		}
		float micro=end.tv_usec - start.tv_usec;
		printf("\n THE TIME TAKEN %1.2f",micro);
		fprintf(fp,"%d time taken is %1.2f",ele,micro);		

	}

}
