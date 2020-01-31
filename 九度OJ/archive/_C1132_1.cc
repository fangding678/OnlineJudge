#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main()
{
    int n,i,cnt;
    bool mark[100];
    int a[100];
    int ans;
    memset(mark, 0, sizeof(mark));
    cnt = 0;
    for(i=1; i<100; ++i)
    {
        if(i%7==0 || i%10==7 || i/10==7)
            continue;
        a[cnt++] = i;
    }
    while(scanf("%d",&n) != EOF)
    {
        ans = 0;
        for(i=0; a[i]<=n; ++i)
            ans += a[i]*a[i];
        printf("%d\n",ans);
    }
    return 0;
}
