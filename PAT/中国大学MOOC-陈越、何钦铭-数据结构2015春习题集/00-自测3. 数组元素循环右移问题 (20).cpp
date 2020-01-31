#include<stdio.h>
#include<stdlib.h>
void reverse(int *a,int low,int high)
{
	int temp;
	while(low<high)
	{
		temp=a[low];
		a[low]=a[high];
		a[high]=temp;
		low++;
		high--;
	}
}
int main()
{
	int *a,n,m,i;
	while(~scanf("%d%d",&n,&m))
	{
		a=(int *)malloc(n*sizeof(int));
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		m%=n;
		reverse(a,0,n-m-1);
		reverse(a,n-m,n-1);
		reverse(a,0,n-1);
		for(i=0;i<n-1;i++) printf("%d ",a[i]);
		printf("%d\n",a[i]);
		free(a);
	}
	return 0;
}
