#include<stdio.h>
#include<sys/time.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

char t[1000],p[1000];

int brute_force()
{
 	int i,j,m,n;
	n=strlen(t);
	m=strlen(p);
	for(i=0;i<(n-m);i++)
	{
		j=0;
		while(j<m && p[j]==t[i+j])
		{
			j++;
			if(j==m)
				return i+1;
		}
	}
	return (-1)	;
}

int main()
{
	struct timeval start,end;
	int pos;
	FILE *fp1=fopen("sid.txt","w");
	printf("Enter the source String:");
	gets(t);
	int n=strlen(t);
	printf("Enter the pattern string for best case:");
	gets(p);

	gettimeofday(&start,NULL);
	pos=brute_force();
	gettimeofday(&end,NULL);
	if(pos==-1)
		printf("\n PATTERN IS NOT PRESENT IN SOURCE");
	else
		printf("\n %s PATTERN IS PRESENT IN SOURCE at INDEX %d ",p,pos);

	float micro=end.tv_usec - start.tv_usec;
	printf("\n TIME TAKEN IS %f ",micro);
  	
	printf("Enter the pattern string for worst case:");
        gets(p);

        gettimeofday(&start,NULL);
        pos=brute_force();
        gettimeofday(&end,NULL);
        if(pos==-1)
                printf("\n PATTERN IS NOT PRESENT IN SOURCE");
        else
                printf("\n %s PATTERN IS PRESENT IN SOURCE at INDEX %d ",p,pos);

        float micro1=end.tv_usec - start.tv_usec;
	
	if(fp1==NULL)
	{
		printf("\n FILE WILL NOT OPEN");
		exit(-1);
	}	
        printf("\n TIME TAKEN IS %1.2f",micro1);
	fprintf(fp1,"%d\t \t %1.2f and %1.2f",n,micro,micro1);
	return 0;	
}


