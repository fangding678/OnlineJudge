#include<stdio.h>
#include<string.h>
int main()
{
	char temp,str[22],s[22];
	int len,value,t,i;
	int a[10],b[10];
	while(gets(str)!=NULL)
	{
		memset(a,0,10*sizeof(int));
		memset(b,0,10*sizeof(int));
		len=strlen(str);
		for(i=0;str[i]!='\0';i++)
		{
			t=str[i]-'0';
			a[t]++;
		}
		value=0;
		for(i=len-1;i>=0;i--)
		{
			t=2*(str[i]-'0')+value;
			value=t/10;
			s[len-i-1]=t%10+'0';
			b[t%10]++;
		}
		if(value!=0){
			s[len++]=value+'0';
			b[value]++;
		}
		s[len]='\0';
		for(i=0;i<10;i++)
			if(a[i]!=b[i])
				break;
		if(i==10) printf("Yes\n");
		else printf("No\n");
		for(i=len-1;i>=0;i--)
			printf("%c",s[i]);
		printf("\n");
	}
	return 0;
}
