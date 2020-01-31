#include<stdio.h>
typedef struct X_L
{
	double x;
	double y;
}X_L;
int main()
{
	X_L v1,v2;
	double a,b;
	while(scanf("%lf%lf%lf%lf",&v1.x,&v1.y,&v2.x,&v2.y)!=EOF)
	{
		a=v1.x+v2.x;b=v1.y+v2.y;
		if((v1.x+v2.x)>-0.05&&(v1.x+v2.x)<0.05) a=0.0;
		if((v1.y+v2.y)>-0.05&&(v1.y+v2.y)<0.05) b=0.0;
		printf("(%0.1lf, %0.1lf)\n",a,b);
	}
	return 0;
}
