#include<stdio.h>
#include<math.h>
int isprime(int n)
{
	if(n==1) return 0;
	if(n==2||n==3) return 1;
	int i;
	for(i=2;i<=sqrt(n);i++)
		if(n%i==0) return 0;
	return 1;
}
int main()
{
	int m,n,i,count,sum;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		count=0;
		sum=0;
		if(m<1||m>n||n>500) continue;
		for(i=m;i<=n;i++)
			if(isprime(i))
			{
				count++;
				sum+=i;
			}
		printf("%d %d\n",count,sum);
	}
	return 0;
}
