#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	int i,j,len;
	char str1[100010],str2[100010];
	while(gets(str1)!=NULL)
	{
		gets(str2);
		len=strlen(str2);
		for(i=0;str1[i]!='\0';i++)
		{
			if(str1[i]=='+')
			{
				for(j=0;j<len;j++)
					if((str2[j]>='A'&&str2[j]<='Z')||str2[j]=='+')
						str2[j]='\0';
				continue;
			}
			for(j=0;j<len;j++)
			{
				if(toupper(str1[i])==toupper(str2[j]))
					str2[j]='\0';
			}
		}
		for(i=0;i<len;i++)
			if(str2[i]!='\0')
				printf("%c",str2[i]);
		printf("\n");
	}
	return 0;
}

