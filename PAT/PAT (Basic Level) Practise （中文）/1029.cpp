#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	char str1[81],str2[81],str3[81];
	int i,j;
	while(~scanf("%s%s",str1,str2))
	{
		str3[0]='\0';
		j=0;
		for(i=0;str1[i]!='\0';i++) str1[i]=toupper(str1[i]);
		for(i=0;str2[i]!='\0';i++) str2[i]=toupper(str2[i]);
		for(i=0;str1[i]!='\0';i++)
			if((!strchr(str2,str1[i]))&&(!strchr(str3,str1[i])))
			{
				str3[j++]=str1[i];
				printf("%c",str1[i]);
			}
		printf("\n");
	}
	return 0;
}
