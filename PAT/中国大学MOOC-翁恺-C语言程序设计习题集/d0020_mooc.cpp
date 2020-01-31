#include<stdio.h>
int main()
{
	int n;
	char e;
	double d1,d2;
	while(scanf("%lf%d",&d1,&n)!=EOF)
	{
		e=getchar();
		while(e==' ')
			scanf("%c",&e);
		scanf("%lf",&d2);
		printf("%c %d %0.2lf %0.2lf\n",e,n,d1,d2);
	}
	return 0;
}

/*#include<stdio.h>
int main()
{
	int n;
	char e;
	double d1,d2;
	while(scanf("%lf%d",&d1,&n)!=EOF)
	{
		//e=getchar();
		//while(e==' ')
			scanf("%c",&e);
		scanf("%lf",&d2);
		printf("%c %d %0.2lf %0.2lf\n",e,n,d1,d2);
	}
	return 0;
}*/
