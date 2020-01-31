#include<stdio.h>
#include<string.h>
int main()
{
	char str[81],e;
	int i,len;
	while(gets(str)!=NULL)
	{
		len=strlen(str);
		for(i=0;i<len/2;i++)
		{
			e=str[i];
			str[i]=str[len-1-i];
			str[len-i-1]=e;
		}
		puts(str);
	}
	return 0;
}
