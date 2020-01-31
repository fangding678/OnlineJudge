#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n,T;
    int result;
    while(~scanf("%d",&T))
    {
        while(T--)
        {
            result = 0;
            scanf("%d",&n);
            while(n)
            {
                ++result;
                n = n&(n-1);
            }
            printf("%d\n",result);
        }
    }
    return 0;
}
