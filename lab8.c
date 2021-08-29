#include<stdio.h>
#include<string.h>
#include<sys/time.h>

int table[127];
void shift_table(char p[])
{
	int m,j,i;
	m=strlen(p);
	for(i=0;i<127;i++)
		table[i]=m;
	for(j=0;j<m-1;j++)
	{
		table[p[j]]=m-1-j;
	}
	
}
int horshpool(char text[],char p[])
{
	int n,m;
	int i=0,k;
	n=strlen(text);
	m=strlen(p);
	i=m-1;
	while(i<n)
	{
		k=0;
		while((k<m) && (p[m-1-k]==text[i-k]))
			k++;
		if(k==m)
			return i-m+1;
		else
			i+=table[text[i]];
	}
	return -1;	
}

int main()
{
	struct timeval start,end;
	int i=0,pos=0,m;
	float t1,t2;
	char text[100],p[100];
	FILE *fp1=fopen("lab8.txt","w");
	for(i=1;i<=3;i++)
	{
		printf("\n ENTER THE text STRING:\n");
		gets(text);
		m=strlen(text);
		printf("\n Enter the Pattern string for search in best case:\n");
		gets(p);
		gettimeofday(&start,0);
		shift_table(p);
		pos=horshpool(text,p);
		gettimeofday(&end,0);
		t1=end.tv_usec-start.tv_usec;
		if(pos>=0)
			printf("\n %d is preset at index in MAIN STRING",pos+1);
		else
			printf("\n THIS PATTERN IS NOT Present in MAIN STring");
		
		printf("\n Enter the Pattern string for search in worst case");
                gets(p);
                gettimeofday(&start,NULL);
                shift_table(p); 
                pos=horshpool(text,p);
                gettimeofday(&end,NULL);
                t2=end.tv_usec-start.tv_usec; 
                if(pos>=0)
                        printf("\n %d is preset at index in MAIN STRING",pos+1);
                else
                        printf("\n THIS PATTERN IS NOT Present in MAIN STring");

		fprintf(fp1,"%d /t %1.2f /t %1.2f",m,t1,t2);
	        printf("\nTime taken is %1.2f and %1.2f to execute \n",t1,t2);
		

	}
}
