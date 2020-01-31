#include <stdio.h>
#include <stdlib.h>
void Reverse(int *a,int n,int k)
{
    int i,t,m;
    for(i=0;i<k/2;i++)
    {
        t=a[i];
        a[i]=a[k-i-1];
        a[k-i-1]=t;
    }
    for(i=k;i<k+(n-k)/2;i++)
    {
        t=a[i];
        a[i]=a[n-i+k-1];
        a[n-i+k-1]=t;
    }
    for(i=0;i<n/2;i++)
    {
        t=a[i];
        a[i]=a[n-1-i];
        a[n-1-i]=t;
    }
    m=n/2;
    for(i=0;i<m/2;i++)
    {
        t=a[i];
        a[i]=a[m-1-i];
        a[m-1-i]=t;
    }
}
int main()
{
    int n=1,k,i,x;
    int *a;
    while(n!=0)
    {
        scanf("%d%d",&n,&k);
        if(n<=0||n>=1000||k<0)
            continue;
        a=(int *)malloc(n*sizeof(int));
        for(i=0;i<n;i++)
            a[i]=i+1;
        for(i=0;i<k;i++)
        {
            scanf("%d",&x);
            Reverse(a,n,x);
        }
        for(i=0;i<n;i++)
            printf("%d ",a[i]);
        printf("\n");
    }
    return 0;
}
