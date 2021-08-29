#include<stdio.h>
int sum,w[100],no,inc[100];
void sumset(int,int,int);
int main()
{
	int total=0,i;
	printf("\n Enter the Number of sumset:");
	scanf("%d",&no);
        printf("Enter %d elements in ascending order\n",no);
	for(i=0;i<no;i++)
	{
		scanf("%d",&w[i]);
		total=total+w[i];
	}
	printf("\n Enter the subset:");
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
		if(wt==sum)
		{
			printf("\n {");
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
