#include<stdio.h>
int main()
{
	int n;
	int a,b;
	while(scanf("%d",&n)!=EOF)
	{
		if(n<0||n>153||n%16>9) continue;
		a=n/16;
		b=n%16;
		printf("%d\n",a*10+b);
	}
	return 0;
}
