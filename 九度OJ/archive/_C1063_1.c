#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,flag;
    while(~scanf("%d",&n))
    {
        if(n>=0) flag=1;
        else flag=-1;
        n*=flag;
        printf("%d\n",3*n*(n+1)*flag/2);
    }
    return 0;
}
