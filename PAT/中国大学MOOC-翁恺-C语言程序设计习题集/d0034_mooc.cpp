#include<stdio.h>
#include<string.h>
int issubstring(char *s1,char *s2)
{
	int i=0,j;
	int len2=strlen(s2);
	while(s1[i+len2-1]!='\0')
	{
		for(j=0;s2[j]!='\0';j++)
			if(s1[i+j]!=s2[j]) break;
		if(s2[j]=='\0') return i;
		i++;
	}
	return -1;
}
int main()
{
	char s1[81],s2[81];
	int i,k,len;
	while(gets(s1)!=NULL)
	{
		gets(s2);
		len=strlen(s2);
		while(issubstring(s1,s2)>=0)
		{
			k=issubstring(s1,s2);
			do{
				s1[k]=s1[k+len];
				k++;
			}while(s1[k+len-1]!='\0');
		}
		puts(s1);
	}
	return 0;
}
