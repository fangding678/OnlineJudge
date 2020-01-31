#include<stdio.h>
#include<stdlib.h>
int main()
{
	int k,i;
	while(scanf("%d",&k)!=EOF)
	{
		if(k<1||k>100000)
			continue;
		int *a=(int *)malloc(k*sizeof(int));
		int sum=0,b=0;
		for(i=0;i<k;i++)
			scanf("%d",&a[i]);
		for(i=0;i<k;i++)
		{
			if(b>0)
				b+=a[i];
			else
				b=a[i];
			if(b>sum)
				sum=b;
		}
		free(a);
		printf("%d\n",sum);
	}
}
