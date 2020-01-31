#include <stdio.h>
#include <stdlib.h>
int m,t;
int isDui(int n)
{
    m=0;
    t=n;
    while(t)
    {
        m=m*10+t%10;
        t/=10;
    }
    if(m==n)
        return 1;
    return 0;
}
int main()
{
    int i;
    for(i=0;i<256;i++)
        if(isDui(i*i))
            printf("%d\n",i);
    return 0;
}
