#include<stdio.h>
int main()
{
	int a[10];
	char str[1001];
	int i;
	while(~scanf("%s",str))
	{
		for(i=0;i<10;i++) a[i]=0;
		for(i=0;str[i]!='\0';i++) a[str[i]-'0']++;
		for(i=0;i<10;i++)
			if(a[i]!=0)
				printf("%d:%d\n",i,a[i]);
	}
	return 0;
}
