#include <stdio.h>
#include <stdlib.h>
int shuhe(int n)
{
    int sum=0;
    while(n)
    {
        sum+=n%10;
        n/=10;
    }
    return sum;
}
int main()
{
    int  n=1;
    while(n!=0)
    {
        scanf("%d",&n);
        if(n<=0||n>=40000)
            continue;
        printf("%d %d\n",shuhe(n),shuhe(n*n));
    }
    return 0;
}
