#include<stdio.h>
char ch[10][5]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
void output(int n)
{
	if(n>=10)
	{
		output(n/10);
		printf(" %s",ch[n%10]);
	}
	else if(n<10&&n>0)
	{
		printf("%s",ch[n]);
		n/=10;
	}
} 
int main()
{
	char str[101];
	int i,sum;
	while(~scanf("%s",str))
	{
		sum=0;
		i=0;
		while(str[i]!='\0')
			sum+=str[i++]-'0';
		output(sum);
		printf("\n");
	}
}
