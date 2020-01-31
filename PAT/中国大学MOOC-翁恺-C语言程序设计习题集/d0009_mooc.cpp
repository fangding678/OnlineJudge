#include<stdio.h>
int main()
{
	int n,m;
	char ch;
	while(scanf("%d%c%d",&n,&ch,&m)!=EOF)
	{
		if(n<0||n>=24||m<0||m>=60||ch!=':') continue;
		if(n<12) printf("%d%c%d AM\n",n,ch,m);
		if(n==12) printf("%d%c%d PM\n",n,ch,m);
		if(n>12) printf("%d%c%d PM\n",n-12,ch,m);
	}
	return 0;
}
