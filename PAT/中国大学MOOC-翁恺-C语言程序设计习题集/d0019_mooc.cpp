#include<stdio.h>
#include<math.h>
int main()
{
	int a,n;
	int i;
	int sum;
	while(scanf("%d%d",&a,&n)!=EOF)
	{
		if(a>9||a<0||n>8||n<1) continue;
		sum=0;
		for(i=0;i<n;i++)
			sum+=(n-i)*a*pow(10,i);
		printf("%d\n",sum);
	}
	return 0;
}
