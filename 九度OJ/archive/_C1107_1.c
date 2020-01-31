#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=1,i,j;
    int *a;
    int min,pmin;
    int sum;
    while(n!=0)
    {
        scanf("%d",&n);
        if(n<=0||n>10000)
            continue;
        a=(int *)malloc(n*sizeof(int));
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        sum=0;
        for(i=0;i<n-1;i++)
        {
            min=(a[i]>a[i+1])?(i+1):i;
            pmin=(a[i]>a[i+1])?i:(i+1);
            for(j=i+2;j<n;j++)
            {
                if(a[j]<a[pmin]&&a[j]>=a[min])
                {
                    pmin=j;
                }
                else if(a[j]<a[pmin]&&a[j]<a[min])
                {
                    pmin=min;
                    min=j;
                }
            }
            sum+=a[min]+a[pmin];
            if(min>pmin)
            {
                a[min]=a[min]+a[pmin];
                a[pmin]=a[i];
            }
            else
            {
                a[pmin]=a[min]+a[pmin];
                a[min]=a[i];
            }
        }
        printf("%d\n",sum);
        free(a);
    }
    return 0;
}
