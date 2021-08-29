#include<stdio.h>
int main()
{
	int cost[10][10],i,j,a,b,min,mincost=0,u,v;
	int ne=1,no,visited[10]={0};
	printf("\n ENter the NUMBER of edge:");
	scanf("%d",&no);
	for(i=1;i<=no;i++)
	{
		printf("\n ROW %d:",i);
		for(j=1;j<=no;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
				cost[i][j]=999;
		}
	}
	visited[1]=1;
	while(ne<no)
	{
		for(i=1,min=999;i<=no;i++)
			for(j=1;j<=no;j++)
				if(cost[i][j]<min)
					if(visited[i]!=0)
			   		{
						min=cost[i][j];
						a=u=i;
						b=v=j;
			   		}
		if(visited[u]==0 || visited[v]==0)
		{
			printf("\n %d:(%d %d)is cost :%d",ne++,a,b,min);
			mincost+=min;
			visited[b]=1;
		}
		cost[a][b]=cost[b][a]=999;
	}
	printf("\n Total Profit is %d",mincost);
	return 0;
}
