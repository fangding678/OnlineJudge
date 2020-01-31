#include<stdio.h>
#include<string.h>
int main()
{
	char str[10000],sign1,sign2,temp;
	int i,zhishu,a,len;
	scanf("%c%d.%[^E]%c%c%d",&sign1,&a,str,&temp,&sign2,&zhishu);
		if(sign1=='-') printf("-");
		if(sign2=='-')
		{
			printf("0.");
			for(i=0;i<zhishu-1;i++)
				printf("0");
			printf("%d",a);
			printf("%s",str);
		}
		else
		{
			len=strlen(str);
			printf("%d",a);
			if(zhishu>=len)
			{
				printf("%s",str);
				for(i=0;i<zhishu-len;i++)
					printf("0");
			}
			else
			{
				for(i=0;i<zhishu;i++)
					printf("%c",str[i]);
				printf(".");
				while(i<len)
					printf("%c",str[i++]);
			}
		}
		printf("\n");
	return 0;
}


/*
#include<stdio.h>
#include<string.h>
int main()
{
	char str[10000],sign1,sign2,temp;
	int i,zhishu,a,len;
	while(~scanf("%c%d.%[^E]%c%c%d",&sign1,&a,str,&temp,&sign2,&zhishu))
	{
		if(sign1=='-') printf("-");
		if(sign2=='-')
		{
			printf("0.");
			for(i=0;i<zhishu-1;i++)
				printf("0");
			printf("%d",a);
			printf("%s",str);
		}
		else
		{
			len=strlen(str);
			printf("%d",a);
			if(zhishu>=len)
			{
				printf("%s",str);
				for(i=0;i<zhishu-len;i++)
					printf("0");
			}
			else
			{
				for(i=0;i<zhishu;i++)
					printf("%c",str[i]);
				printf(".");
				while(i<len)
					printf("%c",str[i++]);
			}
		}
		printf("\n");
	}
	return 0;
}
*/
