#include<stdio.h>
#include<malloc.h>
#include<math.h>
int isprime(int num)
{
	int i;
	for(i=2;i<=sqrt(num);i++)
		if(num%i==0) return 0;
	return 1;
}
int main()
{
	int m,n,i,k;
	int *a;
	while(~scanf("%d%d",&m,&n))
	{
		if(m>n||m<1||n>10000) continue;
		a=(int *)malloc(n*sizeof(int));
		i=1;k=3;
		a[0]=2;
		while(i<n)
		{
			if(isprime(k)) a[i++]=k;
			k+=2;
		}
		k=0;
		for(i=m-1;i<n-1;i++)
		{
			k++;
			if(k%10!=0) printf("%d ",a[i]);
			else printf("%d\n",a[i]);
		}
		printf("%d",a[n-1]);
		if((n-m+1)%10==0) printf("\n");
		free(a);
	}
	return 0;
}
