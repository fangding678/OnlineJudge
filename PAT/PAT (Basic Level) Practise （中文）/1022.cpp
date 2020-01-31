#include<stdio.h>
void verse(int a,int d)
{
	if(a!=0)
	{
		verse(a/d,d);
		printf("%d",a%d);
	}
}
int main()
{
	int a,b,d;
	int i;
	while(~scanf("%d%d%d",&a,&b,&d))
	{
		if(d<2||d>10) continue;
		a+=b;
		if(a==0)
		printf("0");
		verse(a,d);
		printf("\n");
	}
	return 0;
}
