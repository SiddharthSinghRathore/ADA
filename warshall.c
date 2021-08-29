#include<stdio.h>
#include<stdlib.h>
int p[10][10],no,i,j;
void path()
{
	int k=0;
	for(k=0;k<no;k++)
		for(i=0;i<no;i++)
			for(j=0;j<no;j++)
				if(p[i][j]==1 || p[i][k]==1 && p[k][j]==1)
					p[i][j]=1;
}
int main()
{
	printf("\n ENter the number of vertices");
	scanf("%d",&no);
	printf("\n ENter the Adjacency matrix");
	for(i=0;i<no;i++)
	{
		for(j=0;j<no;j++)
		{
			scanf("%d",&p[i][j]);
			if(p[i][j]<0 || p[i][j]>1)
			{
				printf("\n Input value are not allowed");
				exit(0);
			}
		}
	}
	path();
	printf("\n Path matrix is");
	for(i=0;i<no;i++)
	{
		for(j=0;j<no;j++)
		{
			printf(" %d ",p[i][j]);
		}
		printf("\n");
	}
	
}
