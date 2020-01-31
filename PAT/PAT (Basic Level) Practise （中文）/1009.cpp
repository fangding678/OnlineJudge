#include<stdio.h>
void output(char *str,int n)
{
	int t=n,flag=n;
	while(str[n]!='\0'&&str[n]!=' ') n++;
	if(str[n]==' ')
	{
		output(str,n+1);
		while(t<n)
			printf("%c",str[t++]);
		if(flag!=0)
			printf(" ");
		else
			printf("\n");
	}
	else if(str[n]=='\0')
	{
		while(t<n)
			printf("%c",str[t++]);
		if(flag!=0)
			printf(" ");
		else
			printf("\n");
	}
}
int main()
{
	char str[81];
	int n;
	while(gets(str)!=NULL)
	{
		n=0;
		output(str,n);
	}
	return 0;
}



#include <stdio.h>
#include <string.h>
void output(char *str)
{
  char* tail = strchr(str,' ');
  if (tail == NULL)
    printf("%s",str);
  else
    {
      output(tail + 1);
      *tail = '\0';
      printf(" %s",str);
    }
}
int main()
{
  char str[81];
  gets(str);
  output(str);
  putchar('\n');
  return 0;
}

