#include <stdio.h>
#include <stdlib.h>
#define M 1000000
int c[M+2];

int main()
{
    int n,i;
    c[1]=1;c[2]=2;
    for(i=2;i<M;i+=2)
    {
        c[i+1]=c[i];
        c[i+2]=(c[i]+c[i/2+1])%1000000000;
    }
    while(~scanf("%d",&n))
    {
        if(n<1||n>M)
            continue;
        printf("%d\n",c[n]);
    }
    return 0;
}

