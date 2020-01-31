#include<stdio.h>
#include<stdlib.h>
typedef struct People
{
	char s[6];
	int year;
	int month;
	int day;
}People;
int cmp(void const *p1,void const *p2)
{
	if(((People *)(p1))->year>((People *)(p2))->year) return 1;
	else if(((People *)(p1))->year<((People *)(p2))->year) return 0;
	else
	{
		if(((People *)(p1))->month>((People *)(p2))->month) return 1;
		else if(((People *)(p1))->month==((People *)(p2))->month&&((People *)(p1))->day>((People *)(p2))->day) return 1;
		else return 0;
	}
}
int cmp1(People p1,People p2)
{
	if(p1.year>p2.year) return 1;
	else if(p1.year==p2.year)
	{
		if(p1.month>p2.month) return 1;
		else if(p1.month==p2.month&&p1.day>p2.day) return 1;
		else return 0;
	}
	else return 0;
}
int main()
{
	int n,i;
	People *a;
	People p1,p2;
	p1.year=1814;p1.month=9;p1.day=6;
	p2.year=2014;p2.month=9;p2.day=6;
	while(~scanf("%d",&n))
	{
		a=(People *)malloc(n*sizeof(People));
		i=0;
		while(i<n)
		{
			scanf("%s%d/%d/%d",a[i].s,&a[i].year,&a[i].month,&a[i].day);
			if(cmp1(a[i],p2)||cmp1(p1,a[i]))
				n--;
			else
				i++;
		}
		qsort(a,n,sizeof(People),cmp);
		if(n>0) printf("%d %s %s\n",n,a[0].s,a[n-1].s);
		else printf("0\n");
		free(a);
	}
	return 0;
}
