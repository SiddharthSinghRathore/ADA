#include

int g[10][10]={0},flag[10],indeg[10],n,count=0;

int main()
{
printf(“enter the value of n\n”);
scanf(“%d”,&n);

int i,j,k;

printf(“enter the matrix\n”);
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{scanf("%d",&g[i][j]);}
}

for(i=0;i<n;i++)
{
flag[i]=0;
indeg[i]=0;
}

for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
indeg[i]=indeg[i]+g[j][i];
}
}

while(count<n)
{
for(i=0;i”,i+1);
flag[i]=1;
}

for(j=0;j<n;j++)
{
if(g[j][i]==1&&flag[i]==0)//<————————————-
{
indeg[i]–;
break; //<—————————————————–
}
}
}
count++;
}
return 0;
}


