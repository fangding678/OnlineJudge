#include<stdio.h>
int main()
{
	int C1,C2,f;
	while(~scanf("%d%d",&C1,&C2))
	{
		f=(C2-C1+50)/100;
		printf("%02d:%02d:%02d\n",f/3600,f/60%60,f%60);
	}
	return 0;
}
