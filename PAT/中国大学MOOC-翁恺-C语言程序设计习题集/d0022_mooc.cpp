#include<stdio.h>
int main()
{
	char str[41];
	int i;
	while(gets(str)!=NULL)
	{
		i=0;
		while(str[i]!='#')
		{
			if(str[i]>='a'&&str[i]<='z') str[i]-='a'-'A';
			else if(str[i]>='A'&&str[i]<='Z') str[i]+='a'-'A';
			i++;
		}
		str[i]='\0';
		puts(str);
	}
	return 0;
}
