#include <stdio.h>
#include <stdlib.h>

int res(int x,int y,int k)
{
    int t=1;
    while(y)
    {
        if((y&1))
            t=((t%k)*(x%k))%k;
        x=((x%k)*(x%k))%k;
        y=y>>1;
    }
    if(t==0)
        t=k;
    return t;
}
int main()
{
    int x,y,k;
    while(~scanf("%d%d%d",&x,&y,&k))
    {
        printf("%d\n",res(x,y,k-1));
    }
    return 0;
}
