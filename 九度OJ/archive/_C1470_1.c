#include <stdio.h>
#include <stdlib.h>
void swap(int *a,int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}
int main()
{
    int n,i,j,k;
    int a[10][10],b[10];
    while(scanf("%d",&n)!=EOF)
    {
        if(n<1||n>10)
            continue;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                scanf("%d",&a[i][j]);
        for(i=0;i<n;i++)
        {
            b[i]=a[i][i];
            k=i;
            for(j=i+1;j<n;j++)
                if(b[i]<a[j][i])
                {
                    b[i]=a[j][i];
                    k=j;
                }
            if(k!=i)
                for(j=0;j<n;j++)
                    swap(&a[i][j],&a[k][j]);
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
