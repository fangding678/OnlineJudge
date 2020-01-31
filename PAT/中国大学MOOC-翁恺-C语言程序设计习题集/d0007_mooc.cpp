#include<stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n<1||n>1000) continue;
		else if(n%5==1||n%5==2||n%5==3) printf("Fishing in day %d\n",n);
		else printf("Drying in day %d\n",n);
	}
	return 0;
}
