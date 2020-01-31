#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int N;
    int a, i;
    while(~scanf("%d",&N))
    {
        a = 1;
        while(N--)
        {
            a *= 10;
        }
        i=1;
        while(i<a)
            printf("%d\n",i++);
    }
    return 0;
}
