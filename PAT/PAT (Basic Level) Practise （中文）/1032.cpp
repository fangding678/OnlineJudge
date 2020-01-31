#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct B
{
	int x,y;
}B;
int main()
{
	int i,n,max,k;
	int *a;
	B *b;
	while(~scanf("%d",&n))
	{
		a=(int *)malloc((n+1)*sizeof(int));
		b=(B *)malloc(n*sizeof(B));
		memset(a,0,(n+1)*sizeof(int));
		for(i=0;i<n;i++)
			scanf("%d%d",&b[i].x,&b[i].y);
		for(i=0;i<n;i++)
			a[b[i].x]+=b[i].y;
		max=0;k=0;
		for(i=0;i<n+1;i++)
			if(a[i]>max)
			{
				max=a[i];
				k=i;
			}
		printf("%d %d\n",k,max);
		free(a);
		free(b);
	}
	return 0;
}
