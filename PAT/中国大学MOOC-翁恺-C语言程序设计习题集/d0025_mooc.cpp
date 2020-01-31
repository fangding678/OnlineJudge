#include<stdio.h>
int main()
{
	int n,i;
	int a,b,c;
	while(scanf("%d",&n)!=EOF)
	{
		if(n>=1000||n<1) continue;
		a=n/100;
		b=n/10%10;
		c=n%10;
		for(i=0;i<a;i++) printf("B");
		for(i=0;i<b;i++) printf("S");
		for(i=1;i<=c;i++) printf("%d",i);
		printf("\n");
	}
	return 0;
}
