#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int isprime(int n)
{
    int i;
    for(i=2;i<=sqrt(n);i++)
        if(n%i==0)
            return 0;
    return 1;
}
int main()
{
    int n,i;
    while(~scanf("%d",&n))
    {
        if(n<2||n>10000)
            continue;
        else if(n<=11)
        {
            printf("-1\n");
            continue;
        }
        else
        {
            printf("11");
            for(i=21;i<n;i+=10)
                if(isprime(i))
                    printf(" %d",i);
            printf("\n");
        }
    }
    return 0;
}
