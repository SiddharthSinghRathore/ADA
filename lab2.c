#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
int a[5000];
int partition(int l,int h)
{
	int i,j,temp;
	int p=a[l];
	i=l;
	j=h;
	while(i<=j)
	{
		while(a[i] <= p && i<=h)
			i++; 
		while(a[j] > p && j >= l)
			j--;
		if(i<j)
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
	int i=0,j=0,ele,no;
	FILE *fp1=fopen("lab2.txt","w");
	printf("\n ENTER THE Number of itteration");
	scanf("%d",&no);
	for(i=0;i<no;i++)
	{
		printf("\n ENTER THE TOTAL NUMBER");
		scanf("%d",&ele);
		for(j=0;j<ele;j++)
		{
			a[j]=rand()%100;
			printf(" %d ",a[j]);
		}
		gettimeofday(&start,NULL);
		quick_sort(0,ele-1);
		gettimeofday(&end,NULL);
		printf("\n AFTER SORTING\n");
		for(j=0;j<ele;j++)
		{
			printf(" %d ",a[j]);
		}
		float micro=end.tv_usec-start.tv_usec;
		printf("\n TIME TAKE FOR SORTTINF IS %1.2f:",micro);
		fprintf(fp1,"%d \t TIME TAKEN is %1.2f \n",ele,micro);
			
	}
}
