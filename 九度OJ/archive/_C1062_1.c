#include <stdio.h>
#include <stdlib.h>

int main()
{
    double n,y;
    while(~scanf("%lf",&n))
    {
        if(n>=0&&n<2.0)
            y=2.5-n;
        else if(n>=2.0&&n<4.0)
            y=2-1.5*(n-3)*(n-3);
        else if(n>=4.0&&n<6.0)
            y=n/2-1.5;
        else
            continue;
        printf("%0.3lf\n",y);
    }
    return 0;
}
