#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long *a;
    int i,n;
    long long sum,max;
    while(~scanf("%d",&n))
    {
        a=(long long *)malloc(n*sizeof(long long));
        scanf("%lld",&a[0]);
        max=a[0];
        for(i=1;i<n;i++)
        {
            scanf("%lld",&a[i]);
            if(a[i]>max)
                max=a[i];
        }
        if(max<=0)
        {
            printf("%lld\n",max);
            free(a);
            continue;
        }
        sum=max;
        max=0;
        for(i=0;i<n;i++)
        {
            max+=a[i];
            if(max>sum)
                sum=max;
            if(max<=0)
                max=0;
        }
        printf("%lld\n",sum);
        free(a);
    }
    return 0;
}
