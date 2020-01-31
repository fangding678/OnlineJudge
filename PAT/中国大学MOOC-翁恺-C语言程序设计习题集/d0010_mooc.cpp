#include<stdio.h>
int main()
{
	int n;
	char ch;
	while(scanf("%d",&n)!=EOF)
	{
		if(n>100||n<0) continue;
		if(n>=90) ch='A';
		else if(n>=80) ch='B';
		else if(n>=70) ch='C';
		else if(n>=60) ch='D';
		else ch='E';
		printf("%c\n",ch);
	}
}
