#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int wanshu(int a)
{
    int sum=1,i;
    int n=sqrt(a);
    for(i=2;i<=n;i++)
        if(a%i==0)
            sum+=(i+a/i);
    if(a==n*n)
        sum-=n;
    return sum-a;
}
int main()
{
    int i,a[61]={0};
    for(i=2;i<=60;i++)
    {
        if(wanshu(i)==0)
            a[i]=1;
        else if(wanshu(i)>0)
            a[i]=2;
    }
    printf("E:");
    for(i=2;i<=60;i++)
        if(a[i]==1)
            printf(" %d",i);
    printf("\n");
    printf("G:");
    for(i=2;i<=60;i++)
        if(a[i]==2)
            printf(" %d",i);
    printf("\n");
    return 0;
}
