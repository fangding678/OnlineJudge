#include<stdio.h>
int main()
{
	int A,B,a,b;
	int m,n;
	while(~scanf("%d%d%d%d",&A,&a,&B,&b))
	{
		m=0,n=0;
		while(A)
		{
			if(A%10==a) m=m*10+a;
			A/=10;
		}
		while(B)
		{
			if(B%10==b) n=n*10+b;
			B/=10;
		}
		printf("%d\n",m+n);
	}
	return 0;
}
