#include <stdio.h>
#include <stdlib.h>

int isFanxushu(int n)
{
    int m=n,t=0;
    while(m)
    {
        t=t*10+m%10;
        m/=10;
    }
    if(n*9==t)
        return 1;
    else
        return 0;

}
int main()
{
    int i;
    for(i=1000;i<2000;i++)
        if(isFanxushu(i))
            printf("%d\n",i);
    return 0;
}
