#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,x,i;
	int *a;
	while(~scanf("%d%d",&n,&x))
	{
		if(n>20) continue;
		a=(int *)malloc(n*sizeof(int));
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		for(i=0;i<n;i++)
			if(x==a[i]) break;
		if(i==n) printf("Not Found\n");
		else printf("%d\n",i);
		free(a);
	}
	return 0;
}
