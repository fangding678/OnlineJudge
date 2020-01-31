#include<stdio.h>
char a[10][5]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
int output(int n,int m)
{
	if(n>=10) output(n/10,m);
	if(n<m) printf("%s ",a[n%10]);
	if(n>=m) printf("%s\n",a[n%10]);
}
int main()
{
	int n,a,b;
	while(scanf("%d",&n)!=EOF)
	{
		if(n<0){
			printf("fu ");
			n=-n;
		}
		a=n;
		b=1;
		while(a)
		{
			a/=10;
			b*=10;
		}
		b/=10;
		output(n,b);
	}
	return 0;
}
