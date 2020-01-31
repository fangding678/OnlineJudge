#include<stdio.h>
int main()
{
	int a,b,c;
	char ch;
	while(scanf("%d%d%d",&a,&b,&c)!=EOF)
	{
		if(a<1||b<1||c<1||(a==b&&b==c)||(a!=b&&b!=c&&a!=c)) continue;
		else if(a==b&&a!=c) ch='C';
		else if(a==c&&a!=b) ch='B';
		else ch='A';
		printf("%c\n",ch);
	}
	return 0;
}
