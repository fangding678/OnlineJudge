#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main()
{
    int n,i,j,k;
    int **a;
    while(~scanf("%d",&n))
    {
        a=(int **)malloc(n*sizeof(int *));
        for(i=0;i<n;i++)
            *(a+i)=(int *)malloc(n*sizeof(int));
        k=1;
        for(i=0;i<n/2;i++)
        {
            for(j=i;j<n-i;j++)
                a[i][j]=k++;
            for(j=i+1;j<n-i;j++)
                a[j][n-1-i]=k++;
            for(j=n-i-2;j>=i;j--)
                a[n-1-i][j]=k++;
            for(j=n-i-2;j>i;j--)
                a[j][i]=k++;
        }
        if((n&1)==1) a[n/2][n/2]=n*n;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                if(j!=n-1) printf("%d\t",a[i][j]);
                else printf("%d\n",a[i][j]);
            }
    }
    return 0;
}
