#include <stdio.h>
#include <stdlib.h>

int a[1000];
int i,j,value;
void jieCheng(int n)
{
    if(n==0)
    {
        printf("1\n");
        return;
    }
    a[0]=1;
    for(i=1;i<1000;i++)
        a[i]=0;
    for(i=2;i<=n;i++)
    {
        value=0;
        for(j=0;j<=n;j++)
            a[j]=a[j]*i;
        for(j=0;j<n;j++)
        {
            value=a[j]/1000;
            a[j+1]+=value;
            a[j]%=1000;
        }
    }
    for(i=n-1;a[i]==0;i--);
    printf("%d",a[i]);
    for(j=i-1;j>=0;j--)
        printf("%03d",a[j]);
    printf("\n");

}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        if(n<0||n>1000) continue;
        jieCheng(n);
    }
    return 0;
}
