#include<stdio.h>
#define N 101
char s[10][5]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
int main()
{
	char str[N];
	int i,n;
	int a,b,c;
	while(~scanf("%s",str))
	{
		n=0,i=0;
		while(str[i]!='\0') n+=str[i++]-'0';
		c=n%10;
		b=n/10%10;
		a=n/100;
		if(a!=0) printf("%s %s %s\n",s[a],s[b],s[c]);
		if(a==0&&b!=0) printf("%s %s\n",s[b],s[c]);
		if(a==0&&b==0) printf("%s\n",s[c]);
	}
	return 0;
}
