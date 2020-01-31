#include <stdio.h>
#include <stdlib.h>
int main()
{
    double x,result;
    int n,i;
    while(~scanf("%lf%d",&x,&n))
    {
        if(n<0)
            continue;
        result=x;
        for(i=0;i<n;i++)
            result=result*2/3+x/(3*result*result);
        printf("%0.6lf\n",result);
    }
    return 0;
}
