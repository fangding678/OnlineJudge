#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
    return *((int *)a)-*((int *)b);
}
int main()
{
    int n,i;
    int *a;
    while(~scanf("%d",&n))
    {
        a=(int *)malloc(n*sizeof(int));
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        qsort(a,n,sizeof(int),cmp);
        printf("%d\n",a[n-1]);
        if(n==1) printf("-1\n");
        else
        {
            for(i=0;i<n-2;i++)
                printf("%d ",a[i]);
            printf("%d\n",a[i]);
        }
    }
    return 0;
}
