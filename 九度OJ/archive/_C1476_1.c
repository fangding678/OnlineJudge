#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int wangquan(int n)
{
    int i;
    for(i=2;i<=sqrt(n);i++)
        if(n%(i*i)==0)
            return 1;
    return 0;
}
int main()
{
    int n=1;
    while(n!=0)
    {
        scanf("%d",&n);
        if(n<=0||n>=10000)
            continue;
        if(wangquan(n))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
