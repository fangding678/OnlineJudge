#include <stdio.h>

int main()
{
    int m,n;
    int a,b,r;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        if(m<1||n<1)
            continue;
        a=(m>n)?m:n;
        b=(m<=n)?m:n;
        r=a%b;
        while(r)
        {
            a=b;
            b=r;
            r=a%b;
        }
        printf("%d\n",b);
    }
    return 0;
}
