#include<stdio.h>

int main()
{
	int no,a[10][10],indeg[10],flag[10];
	int count=0,i,j,k;
	printf("Enter the no of vertices");
	scanf("%d",&no);
	printf("\n Enter the Adjacency matrix");
	for(i=0;i<no;i++)
	{
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
			if(indeg[k]==0 && flag[k]==0)
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

}
