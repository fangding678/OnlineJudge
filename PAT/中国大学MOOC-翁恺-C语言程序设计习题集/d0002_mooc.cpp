#include <stdio.h>
int main() 
{
	int n;
	int a,b;
	float t;
	while(scanf("%d",&n)!=EOF)
	{
		t=(float)n/30.48;
		a=(int)t;
		t=t-a;
		b=(int)(t*12);
		printf("%d %d\n",a,b);
	}
	return 0;
}
