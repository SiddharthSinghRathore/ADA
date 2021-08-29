#include<stdio.h>

int main()
{
	int a[10][10],flag[10],indeg[10];
	int i,j,count=0,no,k;
	printf("Enter the no of Vertices:");
	scanf("%d",&no);
	printf("\n Enter the Adjacency Matrix");
	for(i=0;i<no;i++)
	{
		printf("\n ROW %d:",i+1);
		for(j=0;j<no;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<no;i++)
	{
		indeg[i]=0;
		flag[i]=0;
	}
	for(i=0;i<no;i++)
		for(j=0;j<no;j++)
			indeg[i]=indeg[i]+a[j][i];
	while(count < no)
	{
		for(k=0;k<no;k++)
		{
			if((indeg[k]==0)&& (flag[k]==0))
			{
				printf(" %d ",(k+1));
				flag[k]=1;
			}
			for(i=0;i<no;i++)
			{
				if(a[i][k]==1)
					indeg[k]--;
			}
		}
		count++;
		
	}
	return 0;
}	
