#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[100][100];
    int n,i,j,t;
    while(~scanf("%d",&n))
    {
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                scanf("%d",&a[i][j]);
        for(i=0;i<n;i++)
            for(j=0;j<i;j++)
            {
                t=a[i][j];
                a[i][j]=a[j][i];
                a[j][i]=t;
            }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n-1;j++)
                printf("%d ",a[i][j]);
            printf("%d\n",a[i][j]);
        }
    }
    return 0;
}
