#include<stdio.h>
#include<math.h>
int isprime(int n)
{
	if(n==2||n==3) return 1;
	if(n%2==0) return 0;
	int i;
	for(i=3;i<=sqrt(n);i++)
		if(n%i==0) return 0;
	return 1;
}
int main()
{
	int m,n,i;
	int count,flag;
	while(~scanf("%d%d",&m,&n))
	{
		if(m>n) continue;
		count=0;i=2;flag=1;
		while(count<n)
		{
			if(isprime(i))count++;
			if(count>=m&&isprime(i))
			{
				if(flag%10!=0&&count!=n) printf("%d ",i);
				else if(flag%10!=0&&count==n) printf("%d\n",i);
				else if(flag%10==0) printf("%d\n",i);
				flag++;
			}
			i++;
		}
	}
	return 0;
}
