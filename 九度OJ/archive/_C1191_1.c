#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,n,i,j,max,k;
    int **a,sum;
    while(~scanf("%d%d",&m,&n))
    {
        a=(int **)malloc(m*sizeof(int *));
        for(i=0;i<m;i++)
            *(a+i)=(int *)malloc(n*sizeof(int));
        for(i=0;i<m;i++)
        {
            max=0;
            sum=0;
            for(j=0;j<n;j++)
            {
                scanf("%d",&a[i][j]);
                sum+=a[i][j];
                if(a[i][j]>max)
                {
                    max=a[i][j];
                    k=j;
                }
            }
            a[i][k]=sum;
        }
        for(i=0;i<m;i++)
        {
            for(j=0;j<n-1;j++)
                printf("%d ",a[i][j]);
            printf("%d\n",a[i][j]);
        }
        for(i=0;i<m;i++)
            free(*(a+i));
        free(a);
    }
    return 0;
}
