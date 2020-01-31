#include<stdio.h>
int main()
{
	char s[1001];
	int sum[1001],result[1001];
	int b,i,j;
	while(~scanf("%s%d",s,&b))
	{
		for(i=0;s[i]!='\0';i++)
			sum[i]=s[i]-'0';
		j=0;
		while(j<i-1)
		{
			result[j]=sum[j]/b;
			sum[j]=sum[j]%b;
			sum[j+1]+=sum[j]*10;
			j++;
		}
		result[j]=sum[j]/b;
		if(result[0]!=0) printf("%d",result[0]);
		for(i=1;i<=j;i++) printf("%d",result[i]);
		if(j==0&&result[0]<b) printf("0");
		printf(" %d\n",sum[j]%b);
	}
	return 0;
}
