#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m=1,i,j;
    int *a;
    a=(int *)malloc(2*m*sizeof(int));
    a[0]=0;
    a[1]=1;
    while(~scanf("%d",&n))
    {
        if(n>m)
        {
            a=(int *)realloc(a,2*n*sizeof(int));
            for(i=2*m;i<2*n-1;i++)
                a[i]=a[i-1]+a[i-2];
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<2*i;j++)
                printf("%d ",a[j]);
            printf("%d\n",a[j]);
        }
    }
    return 0;
}
