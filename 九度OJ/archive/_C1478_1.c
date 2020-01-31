#include <stdio.h>
#include <stdlib.h>
int max(int a,int b,int c)
{
    return (a>b?a:b)>c?(a>b?a:b):c;
}
int main()
{
    int a=1,b,c;
    while(a!=0)
    {
        scanf("%d%d%d",&a,&b,&c);
        if(a<=0||b<1||c<1||a>10000||b>10000||c>10000)
            continue;
        printf("%d\n",a+b+c-2*max(a,b,c));
    }
    return 0;
}
