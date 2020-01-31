#include<stdio.h>
#include<stdlib.h>
int main()
{
	int m,n,i,j;
	int count;
	int **a;
	while(~scanf("%d%d",&m,&n))
	{
		if(m<3||n<3||m>20||n>20) continue;
		count=0;
		a=(int **)malloc(m*sizeof(int *));
		for(i=0;i<n;i++) a[i]=(int *)malloc(n*sizeof(int));
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
				scanf("%d",&a[i][j]);
		for(i=1;i<m-1;i++)
			for(j=1;j<n-1;j++)
				if(a[i][j]>a[i-1][j]&&a[i][j]>a[i+1][j]&&a[i][j]>a[i][j-1]&&a[i][j]>a[i][j+1])
				{
					count++;
					printf("%d %d %d\n",a[i][j],i+1,j+1);
				}
		if(count==0) printf("None %d %d\n",m,n);
		for(i=0;i<m;i++) free(a[i]);
		free(a);
	}
	return 0;
}
