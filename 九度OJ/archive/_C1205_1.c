#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i;
    long long result,a,b;
    while(~scanf("%d",&n))
    {
        if(n<1||n>90)continue;
        result=0;
        a=0;
        b=1;
        for(i=0;i<n;i++)
        {
            result=a+b;
            a=b;
            b=result;
        }
        printf("%lld\n",result);
    }
    return 0;
}
