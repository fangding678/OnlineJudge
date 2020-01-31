#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,i;
	long a,b,c;
	int *d;
	scanf("%d",&n);
	d=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf("%ld%ld%ld",&a,&b,&c);
	d[i]=(a+b>c)?1:0;
	}
	for(i=0;i<n;i++)
	{
		printf("Case #%d: ",i+1);
		if(!d[i]) printf("false\n");
		else printf("true\n");
	}
	free(d);
	return 0;
}

/*
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,i;
	int a,b,c;
	int *d;
	while(~scanf("%d",&n)!=EOF)
	{
		d=(int *)malloc(n*sizeof(int));
		for(i=0;i<n;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			d[i]=(a+b>c)?1:0;
		}
		for(i=0;i<n;i++)
		{
			printf("Case #%d: ",i+1);
			if(!d[i]) printf("false\n");
			else printf("true\n");
		}
		free(d);
	}
	return 0;
}
*/

/*
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,i;
	long a,b,c;
	int *d;
	while(~scanf("%d",&n)!=EOF)
	{
		d=(int *)malloc(n*sizeof(int));
		for(i=0;i<n;i++)
		{
			scanf("%ld%ld%ld",&a,&b,&c);
			d[i]=(a+b>c)?1:0;
		}
		for(i=0;i<n;i++)
		{
			printf("Case #%d: ",i+1);
			if(!d[i]) printf("false\n");
			else printf("true\n");
		}
		free(d);
	}
	return 0;
}
*/
/*
#include<stdio.h>
#include<stdlib.h>
typedef struct Data
{
	long a;
	long b;
	long c;
}Data;
int main()
{
	int n,i;
	Data *d;
	while(~scanf("%d",&n)!=EOF)
	{
		d=(Data *)malloc(n*sizeof(Data));
		for(i=0;i<n;i++)
			scanf("%ld%ld%ld",&d[i].a,&d[i].b,&d[i].c);
		for(i=0;i<n;i++)
		{
			printf("Case #%d: ",i+1);
			if(d[i].a+d[i].b<=d[i].c) printf("false\n");
			else printf("true\n");
		}
		free(d);
	}
	return 0;
}
*/
