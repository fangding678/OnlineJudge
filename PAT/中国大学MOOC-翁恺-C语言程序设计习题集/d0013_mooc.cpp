#include<stdio.h>
int main()
{
	int n;
	int i,j;
	while(scanf("%d",&n)!=EOF)
	{
		if(n<1||n>9) continue;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=i;j++)
				printf("%d*%d=%-4d",j,i,i*j);
			printf("\n");
		}
	}
	return 0;
}
