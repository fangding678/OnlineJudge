#include<stdio.h>
typedef struct Num
{
	long A;
	long B;
	long C;
}Num;
int main()
{
	int i,T;
	Num a[10];
	while(~scanf("%d",&T))
	{
		for(i=0;i<T;i++)
			scanf("%ld%ld%ld",&a[i].A,&a[i].B,&a[i].C);
		for(i=0;i<T;i++)
		{
			if(a[i].A+a[i].B<=a[i].C)
				printf("Case #%d: false\n",i+1);
			else
				printf("Case #%d: true\n",i+1);
		}
	}
	return 0;
}
