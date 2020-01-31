#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int result;
    int n;
    while(~scanf("%d",&n))
    {
        if(n<1||n>20)
            continue;
        result=1;
        while(n)
            result*=n--;
        printf("%lld\n",result);
    }
    return 0;
}
