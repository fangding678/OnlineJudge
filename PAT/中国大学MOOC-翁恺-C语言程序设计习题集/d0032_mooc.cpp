#include<stdio.h>
void output(char *str)
{
	int i=0;
	int j;
	while(str[i]!=' '&&str[i]!='\0') i++;
	if(str[i]==' ') output(str+i+1);
	if(str[i]==' ') printf(" ");
	for(j=0;j<i;j++) printf("%c",str[j]);
}
int main()
{
	char str[80];
	while(gets(str)!=NULL)
	{
		output(str);
		printf("\n");
	}
	return 0;
}
