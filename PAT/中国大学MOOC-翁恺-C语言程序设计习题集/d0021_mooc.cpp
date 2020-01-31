#include<stdio.h>
int main()
{
	int a,b;
	int flag;
	char ch;
//	while(scanf("%d",&a)!=EOF)
//	{
		scanf("%d",&a);
		scanf("%c",&ch);
		flag=0;
		while(ch!='=')
		{
			scanf("%d",&b);
			switch(ch)
			{
				case '+':
					a+=b;
					break;
				case '-':
					a-=b;
					break;
				case '*':
					a*=b;
					break;
				case '/':
					if(b==0)
						flag=1;
					else a/=b;
					break;
				default :
					flag=1;
					break;
			}
			if(flag==1) break;
			scanf("%c",&ch);
		}
		if(flag==1) printf("ERROR\n");
		else printf("%d\n",a);
//	}
}
