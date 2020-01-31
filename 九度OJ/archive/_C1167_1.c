#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j,min;
    int *a,*b;
    while(~scanf("%d",&n))
    {
        if(n<1||n>10000)
            continue;
        a=(int *)malloc(n*sizeof(int));
        b=(int *)calloc(n,sizeof(int));
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        min=0;
        for(i=1;i<n;i++)
            if(a[i]<a[min])
                min=i;
        for(i=0;i<n;i++)
            if(a[i]==a[min])
                b[i]=1;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(a[j]>a[min])
                    b[j]=b[min]+1;
            }
            for(j=0;j<n;j++)
                if(b[j]==b[min]+1)
                    break;
            if(j==n) break;
            min=j;
            for(j=0;j<n;j++)
                if(b[j]==b[min]&&a[j]<a[min])
                    min=j;
        }
        for(i=0;i<n-1;i++)
            printf("%d ",b[i]);
        printf("%d\n",b[i]);
    }
    return 0;
}
