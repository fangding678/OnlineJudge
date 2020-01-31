#include<stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n<0||n>500) continue;
		else if(n<=60) printf("Speed: %d - OK\n",n);
		else printf("Speed: %d - Speeding\n",n);
	}
	return 0;
}
