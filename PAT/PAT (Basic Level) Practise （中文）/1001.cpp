#include<stdio.h>
int Num(int n)
{
	int sum=0;
	while(n!=1)
	{
		if((n&1)==0) n=n>>1;
		else n=(3*n+1)>>1;
		sum++;
	}
	return sum;
}
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		if(n<0||n>1000) continue;
		printf("%d\n",Num(n));
	}
	return 0;
}
