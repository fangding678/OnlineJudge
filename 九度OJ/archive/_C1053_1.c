#include <stdio.h>
int main()
{
    int n,i;
    int a[20];
    while(scanf("%d",&n)!=EOF)
    {
        int j=0,k=0,t;
        if(n<1||n>20)
            continue;
        scanf("%d",&a[0]);
        int max=a[0];
        int min=a[0];
        for(i=1;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]>max)
            {
                max=a[i];
                j=i;
            }
            if(a[i]<min)
            {
                min=a[i];
                k=i;
            }
        }
        t=a[j];a[j]=a[k];a[k]=t;
        for(i=0;i<n-1;i++)
            printf("%d ",a[i]);
        printf("%d\n",a[n-1]);
    }
    return 0;
}
