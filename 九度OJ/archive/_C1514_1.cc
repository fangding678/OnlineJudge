#include <iostream>
#include <cstdio>

using namespace std;

double myPower(double base, int exponent)
{
    bool flag = false;
    if(exponent < 0)
    {
        exponent = 0 - exponent;
        flag = true;
    }
    double result = 1.0;
    if(exponent)
    {
        result = myPower(base, exponent/2);
        result *= result;
        if((exponent&1)==1)
            result *= base;
    }
    if(flag)
        result = 1.0/result;
    return result;
}

int main()
{
    int T;
    int exponent;
    double base;
    double result;
    while(~scanf("%d",&T))
    {
        while(T--)
        {
            scanf("%lf%d",&base,&exponent);
            if(base == 0.0)
            {
                if(exponent >= 0)
                    printf("%.2ef\n", 0.0);
                else
                    printf("INF\n");
            }
            else
            {
                result = myPower(base, exponent);
                printf("%.2ef\n", result);
            }
        }
    }
    return 0;
}
