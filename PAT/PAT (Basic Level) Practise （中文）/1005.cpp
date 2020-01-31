#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
int Clz(int m,int n)
{
	while(m!=1)
	{
		if(m==n) return 1;
		if((m&1)==0) m=m>>1;
		else m=(3*m+1)>>1;
	}
	return 0;
}
int compAs(const void *a,const void *b)
{
	return *(int *)b-*(int *)a;
}
int main()
{
	int k,i,j;
	int *a,b[101];
	while(~scanf("%d",&k))
	{
		if(k>=100||k<1) continue;
		a=(int *)malloc(k*sizeof(int));
		memset(b,0,101*sizeof(int));
		for(i=0;i<k;i++)
			scanf("%d",&a[i]);
		qsort(a,k,sizeof(a[0]),compAs);
		for(i=0;i<k-1;i++)
		{
			for(j=i+1;j<k;j++)
			{
				if(Clz(a[i],a[j]))
					b[a[j]]=1;
				else if(Clz(a[j],a[i]))
					b[a[i]]=1;
			}
		}
		while(b[a[--k]]==1);
		for(i=0;i<k;i++)
			if(b[a[i]]==0)
				printf("%d ",a[i]);
		printf("%d\n",a[k]);
		free(a);
	}
	return 0;
}
