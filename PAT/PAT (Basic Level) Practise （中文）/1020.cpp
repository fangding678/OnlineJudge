#include<stdio.h>
#include<stdlib.h>
typedef struct Yue
{
	double weight;
	double price;
	double avg;
}Yue;
int cmp(const void *a,const void *b)
{
	return ((Yue *)b)->price*((Yue *)a)->weight - ((Yue *)a)->price*((Yue *)b)->weight;
}
int main()
{
	int n,d;
	Yue *a;
	int i;
	double result;
	while(~scanf("%d%d",&n,&d))
	{
		if(n>1000||n<1||d>500||d<1) continue;
		a=(Yue *)malloc(n*sizeof(Yue));
		for(i=0;i<n;i++) scanf("%lf",&a[i].weight);
		for(i=0;i<n;i++)
		{
			scanf("%lf",&a[i].price);
			a[i].avg=a[i].price/a[i].weight;
		}
		qsort(a,n,sizeof(Yue),cmp);
		i=0;result=0.0;
		while(d>0&&i<n)
		{
			if(d>=a[i].weight)
			{
				result+=a[i].price;
				d-=a[i].weight;
			}
			else
			{
				result+=a[i].avg*d;
				d=0;
			}
			i++;
		}
		printf("%0.2lf\n",result);
		free(a);
	}
	return 0;
}
