#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
    int n,i,j,t;
    int dp1[101],dp2[101];
    //int dp3[101];
    int a[101],ans;
    //int b[101];
    while(scanf("%d",&n) != EOF)
    {
        for(i=1; i<=n; ++i)
            scanf("%d",&a[i]);
        for(i=1; i<=n; ++i)
        {
            dp1[i] = 1;
            dp2[i] = 1;
        }
        for(i=2; i<=n; ++i)
        {
            for(j=1; j<i; ++j)
            {
                if(a[i] > a[j])
                    dp1[i] = max(dp1[i], dp1[j]+1);
            }
        }
        for(i=n-1; i>=1; --i)
        {
            for(j=n; j>i; --j)
            {
                if(a[i] > a[j])
                    dp2[i] = max(dp2[i], dp2[j]+1);
            }
        }
        ans = 101;
        /*t = 0;
        dp3[n] = 0;
        b[n] = 0;
        for(i=n-1; i>=1; --i)
        {
            if(t < dp2[i+1])
            {
                t = dp2[i+1];
                dp3[i] = t;
                b[i] = i+1;
            }
        }*/
        for(i=1; i<=n; ++i)
        {
            t = 0;
            for(j=i+1; j<=n; ++j)
            {
                if(dp2[j] > t && a[j] != a[i])
                {
                    t = dp2[j];
                }
            }
            ans = min(ans, n-dp1[i]-t);
        }
        printf("%d\n",ans);
    }
    return 0;
}
