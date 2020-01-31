#include<stdio.h>
int main()
{
	int n,m;
	int a,b,r;
	char e;
	while(scanf("%d",&n)!=EOF)
	{
		scanf("%c%d",&e,&m);
		if(n<1||m<1||e!='/') continue;
		a=(m>n)?m:n;
		b=(m<n)?m:n;
		r=a%b;
		while(r)
		{
			a=b;
			b=r;
			r=a%b;
		}
		printf("%d%c%d\n",n/b,e,m/b);
	}
	return 0;
}
