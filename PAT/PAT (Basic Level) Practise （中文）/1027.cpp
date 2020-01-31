#include<stdio.h>
#include<math.h>
int main()
{
	int n,k,i,j;
	char e;
	while(~scanf("%d",&n))
	{
		getchar();
		scanf("%c",&e);
		k=sqrt((n+1)/2);
		for(i=k;i>0;i--)
		{
			for(j=k;j>i;j--)
				printf(" ");
			for(j=0;j<2*i-1;j++)
				printf("%c",e);
			printf("\n");
		}
		for(i=2;i<=k;i++)
		{
			for(j=k;j>i;j--)
				printf(" ");
			for(j=0;j<2*i-1;j++)
				printf("%c",e);
			printf("\n");
		}
		printf("%d\n",n-2*k*k+1);
	}
	return 0;
}
