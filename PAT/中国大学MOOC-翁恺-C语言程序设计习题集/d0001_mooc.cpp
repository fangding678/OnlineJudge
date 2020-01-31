#include<stdio.h>
int main()
{
	int A,B;
	while(scanf("%d%d",&A,&B)!=EOF)
	{
		printf("%d + %d = %d\n",A,B,A+B);
		printf("%d - %d = %d\n",A,B,A-B);
		printf("%d * %d = %d\n",A,B,A*B);
		printf("%d / %d = %d\n",A,B,A/B);
	}
}
