#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n,i,m;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0; i<n; ++i)
        {
            scanf("%d",&m);
            if((m&1)==1)
                printf("0 0\n");
            else
            {
                printf("%d %d\n",(m+2)/4,m/2);
            }
        }
    }
    return 0;
}
