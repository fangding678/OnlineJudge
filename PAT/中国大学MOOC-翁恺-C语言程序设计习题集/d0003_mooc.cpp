#include<stdio.h>
int main()
{
	int a,b;
	int m,n,c;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		m=a/100;
		n=a%100;
		c=m*60+n+b;
		m=c/60;
		n=c%60;
		if(m>=24||m<0)	continue;
		printf("%d\n",m*100+n);
	}
}
