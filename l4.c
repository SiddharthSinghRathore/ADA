#include<stdio.h>
int main()
{
	int i,j,no,cost[10][10],min,mincost;
	int ne=1,a,b,u,v;
	int visited[10]={0};
	printf("\n ENter the No of vertices");
	scanf("%d",&no);
	printf("\n ENter the adjacency matrix");
	for(i=1;i<=no;i++)
	{
		printf("\n No of Rows %d:",i);
		for(j=1;j<=no;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
				cost[i][j]=999;
		}
	}
	visited[1]=1;
	while(ne < no)
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
			printf("\n %d:(%d %d) is cost %d ",ne++,a,b,min);
			mincost+=min;
			visited[b]=1;
			
		}
		cost[a][b]=cost[b][a]=999;
	}
	printf("\n mincost is %d",mincost);
	return 0;
}
