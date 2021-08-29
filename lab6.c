#include<stdio.h>
int max(int a,int b)
{
	return(a > b)? a : b;
}
int knapsack(int W,int set[],int val[],int no)
{
	int i,w;
	int k[no+1][W+1];
	for(i=0;i<=no;i++)
	{
		for(w=0;w<=W;w++)
		{
			if(i==0 || w==0)
				k[i][w]=0;
			else if(set[i-1]<=w)
				k[i][w]=max(val[i-1]+k[i-1][w-set[i-1]],k[i-1][w]);
			else
				k[i][w]=k[i-1][w];
		}
	}
   	printf("\n============================================");
	printf("\n Path matrix");
	for(i=0;i<=no;i++)
	{
		printf("\n");
		for(w=0;w<=W;w++)
		{
			printf("%d\t",k[i][w]);
		}
	}
	return k[no][W];
}
int main()
{
	int no,set[10],val[10],i,W;
	printf("Enter the Limit of Item");
	scanf("%d",&no);
	printf("\n Enter the weight  and value");
	for(i=0;i<no;i++)
	{
		scanf("%d %d",&set[i],&val[i]);
	}
	printf("\n ENter the maximun weight");
	scanf("%d",&W);
	printf("\n Total profit==>%d",knapsack(W,set,val,no));	

}
