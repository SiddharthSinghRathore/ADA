#include<stdio.h>
int max(int a,int b)
{
	return (a > b) ? a:b;
}
int knapsack(int W,int set[],int val[],int no)
{
	int i,w;
	int x[no];
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
	printf("\n ====================================================");
	printf("\n Path Matrix");
	for(i=0;i<=no;i++)
	{
		printf("\n");
		for(w=0;w<=W;w++)
		{
			printf("%d\t",k[i][w]);
		}
	}
	printf("\n ======================================");
	i=no;
	w=W;
/*	while(i!=0 && w!=0)
	{
		if(k[i][w]!=k[i-1][w])
		{
			x[i]=1;
			w=w-set[i-1];
		}
		i--;
	}
	printf("\n Selected Object");
	for(i=1;i<=no;i++)
		printf("%d\t",i);*/
	printf("\n");
	for(i=1;i<=no;i++)
	{
		if(x[i]==1)
			printf("1\t");
		else
			printf("0\t");
	}
	printf("\n");
	
	return k[no][W];
}

int main()
{
	int no,set[50],val[50],i,W;
	printf("\n ENter the Limit of object");
	scanf("%d",&no);
	printf("\n ENter the weight and value");
	for(i=0;i<no;i++)
	{
		scanf("%d %d",&set[i],&val[i]);
	}
	printf("\n ENter the Maximum Weight");
	scanf("%d",&W);
	printf("\n Total Profit Is %d",knapsack(W,set,val,no));
}
