#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void *a,const void *b)
{
	return *((int *)a)-*((int *)b);
}
int isSort(int *a,int low,int high)
{
	int i;
	for(i=low;i<high-1;i++)
		if(a[i]>a[i+1]) break;
	if(i<high-1) return 0;
	return 1;
}
void Insertion(int *a,int n,int m)
{
	int i;
	printf("Insertion Sort\n");
	if(m<n) qsort(a,m+1,sizeof(int),cmp);
	for(i=0;i<n-1;i++) printf("%d ",a[i]);
	printf("%d\n",a[i]);
}
void Merge(int *a,int n,int m)
{
	int i,k;
	printf("Merge Sort\n");
	k=n/(2*m);
	for(i=0;i<k;i++) qsort(a+2*i*m,2*m,sizeof(int),cmp);
	if(n%(2*m)!=0) qsort(a+2*k*m,n-2*k*m,sizeof(int),cmp);
	for(i=0;i<n-1;i++) printf("%d ",a[i]);
	printf("%d\n",a[i]);
}
int main()
{
	int n,i,m,k,flag,f;
	int *a,*b,*c;
	while(~scanf("%d",&n))
	{
		m=1;
		a=(int *)malloc(n*sizeof(int));
		b=(int *)malloc(n*sizeof(int));
		c=(int *)malloc(n*sizeof(int));
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		for(i=0;i<n;i++){
			scanf("%d",&b[i]);
			c[i]=a[i];
		}
		for(i=1;i<n;i++){
			if(b[i-1]<=b[i])
				m++;
			else break;
		}
		qsort(c,m,sizeof(int),cmp);
		for(i=0;i<n;i++)
			if(b[i]!=c[i]) break;
		if(n==i) flag=1;
		else{
			flag=2;f=0;
			while(f!=1)
			{
				f=1;
				k=n/m;
				for(i=0;i<k;i++)
					if(!isSort(b,i*m,(i+1)*m))
						f=0;
				if(!isSort(b,i*m,n)) f=0;
				if(f==0) m/=2;
			}
		}
		switch(flag)
		{
			case 1:
				Insertion(b,n,m);
				break;
			case 2:
				Merge(b,n,m);
				break;
		}
		free(a);
		free(b);
	}
	return 0;
}
