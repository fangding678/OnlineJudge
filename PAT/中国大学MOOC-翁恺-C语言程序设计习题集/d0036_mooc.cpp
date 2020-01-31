#include<stdio.h>
#include<string.h>
void reverse(char *s,int low,int high)
{
	char t;
	while(low<high)
	{
		t=*(s+low);
		*(s+low)=*(s+high);
		*(s+high)=t;
		low++;
		high--;
	}
}
int main() 
{
	char str[101];
	int n,len;
	while(gets(str)!=NULL)
	{
		scanf("%d",&n);
		getchar();
		if(str==NULL||n<0) continue;
		len=strlen(str);
		n=n%len;
		if(n!=0){
			reverse(str,0,n-1);
			reverse(str,n,len-1);
			reverse(str,0,len-1);
		}
		puts(str);
	}
	return 0;
}

/*
#include<stdio.h>
#include<string.h>
void reverse(char *s,int low,int high)
{
	char t;
	while(low<high)
	{
		t=*(s+low);
		*(s+low)=*(s+high);
		*(s+high)=t;
		low++;
		high--;
	}
}
int main()
{
	char str[101];
	int n,len;
	while(gets(str)!=NULL)
	{
		scanf("%d",&n);
		if(str==NULL||n<0) continue;
		len=strlen(str);
		n=n%len;
		if(n!=0){
			reverse(str,0,n-1);
			reverse(str,n,len-1);
			reverse(str,0,len-1);
		}
		puts(str);
	}
	return 0;
}
*/
