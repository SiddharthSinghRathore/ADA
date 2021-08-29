#include<stdio.h>
int w[100],sum,inc[100],no;
void sumset(int,int,int);
int main()
{
	int total=0,i;
	printf("\n ENter the number of subset:");
	scanf("%d",&no);
        printf("Enter %d elements in ascending order\n",no);
	for(i=0;i<no;i++)
	{
		scanf("%d",&w[i]);
		total=total+w[i];
	}
	printf("\n ENter the Subset");
	scanf("%d",&sum);
	sumset(-1,0,total);
	return 0;
	
}

int promising(int i,int wt,int total)
{
	return (((total+wt)>=sum) && ((wt==sum) || (wt+w[i+1]<=sum)));
}
void sumset(int i,int wt,int total)
{
	int j=0;
	if(promising(i,wt,total))
	{
		if(sum==wt)
		{
			printf("\n{");
			for(j=0;j<no;j++)
			{
				if(inc[j]==1)
					printf(" %d ",w[j]);
			}
			printf("}\n");
			
		}
		else
		{
			inc[i+1]=1;
			sumset(i+1,wt+w[i+1],total-w[i+1]);
			inc[i+1]=0;
			sumset(i+1,wt,total-w[i+1]);
		}
	}
}
