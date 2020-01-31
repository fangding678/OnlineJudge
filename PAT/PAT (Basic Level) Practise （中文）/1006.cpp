#include<stdio.h>
int main()
{
	int a,b,c;
	int n,i;
	while(~scanf("%d",&n))
	{
		if(n<1||n>=1000)
			continue;
		a=n/100;
		b=n/10%10;
		c=n%10;
		for(i=0;i<a;i++) printf("B");
		for(i=0;i<b;i++) printf("S");
		for(i=0;i<c;i++) printf("%d",i+1);
		printf("\n");
	}
	return 0;
}
