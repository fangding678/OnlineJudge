#include<stdio.h>
#include<math.h>
int isprime(int n)
{
	int i;
	for(i=2;i<=sqrt(n);i++)
		if(n%i==0) return 0;
	return 1;
}
int main()
{
	int n,i,sum,t;
	while(~scanf("%d",&n))
	{
		if(n>=100000||n<1) continue;
		sum=0;t=3;
		for(i=4;i<=n;i++)
			if(isprime(i))
			{
				if((i-t)==2) sum++;
				t=i;
			}
		printf("%d\n",sum);
	}
	return 0;
}
