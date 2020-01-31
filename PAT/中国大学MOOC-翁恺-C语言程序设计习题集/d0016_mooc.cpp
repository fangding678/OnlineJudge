#include<stdio.h>
int main()
{
	int n,i;
	double a,b,t;
	double sum;
	while(scanf("%d",&n)!=EOF)
	{
		if(n<1) continue;
		a=2.0; b=1.0; sum=0.0;
		for(i=0;i<n;i++)
		{
			sum+=a/b;
			t=a;
			a=a+b;
			b=t;
		}
		printf("%0.2lf\n",sum);
	}
	return 0;
}
