#include<stdio.h>
int main()
{
	char e,str[80];
	int i;
	while(gets(str)!=NULL)
	{
		e=getchar();
		if(e=='\n') scanf("%c",&e);
		i=0;
		while(str[i]!='\0'){
			if(str[i]==e) break;
			i++;
		}
		if(str[i]=='\0') printf("Not found");
		while(str[i]!='\0') printf("%c",str[i++]);
		printf("\n");
		e=getchar();
	}
	return 0;
}
