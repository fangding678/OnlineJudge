#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
	return (*(int *)b)-(*(int *)a);
}
int main()
{
	int a[4];
	int n,m,result;
	while(~scanf("%d",&result))
	{
		if(result<1||result>=10000) continue;
		a[0]=result/1000;
		a[1]=result/100%10;
		a[2]=result/10%10;
		a[3]=result%10;
		qsort(a,4,sizeof(int),cmp);
		m=1000*a[0]+100*a[1]+10*a[2]+a[3];
		n=1000*a[3]+100*a[2]+10*a[1]+a[0];
		result=m-n;
		printf("%04d - %04d = %04d\n",m,n,result);
		while(result!=6174&&a[0]!=a[3])
		{
			a[0]=result/1000;
			a[1]=result/100%10;
			a[2]=result/10%10;
			a[3]=result%10;
			qsort(a,4,sizeof(int),cmp);
			m=1000*a[0]+100*a[1]+10*a[2]+a[3];
			n=1000*a[3]+100*a[2]+10*a[1]+a[0];
			result=m-n;
			printf("%04d - %04d = %04d\n",m,n,result);
		}
	}
	return 0;
}
