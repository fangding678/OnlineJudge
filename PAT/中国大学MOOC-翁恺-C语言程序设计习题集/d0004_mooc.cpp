#include<stdio.h>
int main()
{
	int n;
	int a,b,c;
	while(scanf("%d",&n)!=EOF)
	{
		if(n<100||n>=1000)continue;
		c=n%10;
		b=n/10%10;
		a=n/100;
		n=a+b*10+c*100;
		printf("%d\n",n);
	}
}
