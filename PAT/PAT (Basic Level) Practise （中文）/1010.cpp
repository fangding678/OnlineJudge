#include<stdio.h>
#include<string.h>
typedef struct Num
{
	int x;
	int y;
}Num;
int main()
{
	Num a[2001];
	int i=0,j,k=0;
	while(scanf("%d%d",&a[i].x,&a[i].y)!=EOF) i++;
	for(j=0;j<i;j++)
		if(a[j].y)
		{
			a[k].x*=a[k].y;
			a[k++].y--;
		}
	if(k!=0)
		printf("%d %d",a[0].x,a[0].y);
	for(j=1;j<k;j++)
		printf(" %d %d",a[j].x,a[j].y);
	if(k==0)
		printf("0 0");
	printf("\n");
	return 0;
}


/*#include<stdio.h>
#include<string.h>
typedef struct Num
{
	int a;
	int b;
}Num;
int tran(char *str,char *tail)
{
	int result=0,flag=0;
	char *temp=str;
	if(*temp=='-')
	{
		temp++;
		flag=1;
	}
	while(temp!=tail&&temp!='\0')
	{
		result=result*10+*temp-'0';
		temp++;
	}
	if(flag==1)
		result=-result;
	return result;
}
int main()
{
	Num Arr[2001];
	int i,j,f;
	char *tail,*head;
	char str[10000];
	while(gets(str)!=NULL)
	{
		i=0;head=str;j=0;
		tail=strchr(head,' ');
		while(tail!=NULL)
		{
			if(j&1==0)
				Arr[i].a=tran(head,tail);
			else
				Arr[i++].b=tran(head,tail);
			head=tail+1;
			j++;
			tail=strchr(head,' ');
		}
		for(j=0;j<i;j++)
		{
			Arr[j].a*=Arr[j].b;
			Arr[j].b--;
		}
		f=0;
		for(j=0;j<i;j++)
		{
			if(Arr[j].a!=0)
			{
				if(f!=0)
					printf(" %d %d",Arr[j].a,Arr[j].b);
				else
					printf("%d %d",Arr[j].a,Arr[j].b);
			}
		}
		printf("\n");
	}
	return 0;
}
*/
