#include<stdio.h>
#include<stdlib.h>
int main()
{
	int k,i;
	int *a;
	while(scanf("%d",&k)!=EOF)
	{
		if(k<1||k>10000) continue;
		int sum=0,b=0;
		int f=0,l=k,t=0;
		a=(int *)malloc(k*sizeof(int));
		for(i=0;i<k;i++)
		{
			scanf("%d",&a[i]);
			if(b>0) b+=a[i];
			else
			{
				b=a[i];
				t=i;
			}
			if(b==0&&sum==0) {
				t=i;l=i;
			}
			if(b>sum)
			{
				sum=b;
				l=i;
			}
			if(t<=l&&l!=k) f=t;
		}
		if(l==k) l--;
		printf("%d %d %d\n",sum,a[f],a[l]);
		free(a);
	}
	return 0;
}
