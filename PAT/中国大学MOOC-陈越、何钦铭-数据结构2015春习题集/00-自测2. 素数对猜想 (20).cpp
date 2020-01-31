#include<stdio.h>
#include<math.h>
int isPrime(int a)
{
	int i,t=sqrt(a);
	for(i=3;i<=t;i+=2)
		if(a%i==0) return 0;
	return 1;
}
int main()
{
	int n,i,k;
	while(~scanf("%d",&n))
	{
		if(n<1||n>100000) continue;
		k=0;
		for(i=3;i<=n-2;i+=2)
			if(isPrime(i)&&isPrime(i+2)) k++;
		printf("%d\n",k);
	}
	return 0;
}
