#include<stdio.h>
typedef struct B
{
	int x,y;
}B;
int main()
{
	B a[2010];
	int n=0,i;
	while(~scanf("%d%d",&a[n].x,&a[n].y)) n++;
	if(n==1&&a[0].y==0) printf("0 0\n");
	else
	{
		if(a[0].y!=0){
			printf("%d %d",a[0].x*a[0].y,a[0].y-1);
			for(i=1;i<n;i++)
			{
				if(a[i].y==0) continue;
				printf(" %d %d",a[i].x*a[i].y,a[i].y-1);
			}
		}
		else{
			printf("%d %d",a[1].x*a[1].y,a[1].y-1);
			for(i=2;i<n;i++)
				printf(" %d %d",a[i].x*a[i].y,a[i].y-1);
		}
		putchar(10);
	}
	return 0;
}
