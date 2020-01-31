#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *a,*b;
    int i,j,n,m;
    while(~scanf("%d",&n))
    {
        a=(int *)malloc((n+1)*sizeof(int));
        b=(int *)malloc((n+1)*sizeof(int));
        a[0]=a[1]=1;
        b[0]=1;
        m=2;
        for(i=1;i<n;i++)
        {
            if(m%2==0)
            {
                for(j=0;j<m-1;j++)
                {
                    printf("%d ",a[j]);
                    b[j+1]=a[j]+a[j+1];
                }
                printf("%d\n",a[j]);
                b[m]=1;
            }
            else
            {
                for(j=0;j<m-1;j++)
                {
                    printf("%d ",b[j]);
                    a[j+1]=b[j]+b[j+1];
                }
                printf("%d\n",b[j]);
                a[m]=1;
            }
            m++;
        }
        free(a);
        free(b);
    }
    return 0;
}
