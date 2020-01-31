#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int a[101][101],dp[101][101],tmp[101][101];
    int i,j,k,n,t,ans;
    while(cin>>n)
    {
        ans = -300;
        for(i=1; i<=n; ++i)
        {
            for(j=1; j<=n; ++j)
            {
                cin>>a[i][j];
                if(ans < a[i][j])
                    ans = a[i][j];
            }
        }
        if(ans <= 0)
        {
            cout<<ans<<endl;
            continue;
        }
        memset(dp, 0, sizeof(dp));
        memset(tmp, 0, sizeof(tmp));
        for(i=1; i<=n; ++i)
        {
            for(j=1; j<=n; ++j)
            {
                t = 0;
                for(k=j; k<=n; ++k)
                {
                    t += a[i][k];
                    if(t < 0)
                    {
                        if(tmp[j][k] + t > 0)
                        {
                            tmp[j][k] = tmp[j][k] + t;
                        }
                        else
                        {
                            tmp[j][k] = 0;
                        }
                    }
                    else
                    {
                        tmp[j][k] += t;
                        if(dp[j][k] < tmp[j][k])
                            dp[j][k] = tmp[j][k];
                    }
                }
            }
        }
        ans = -300;
        for(j=1; j<=n; ++j)
        {
            for(k=j; k<=n; ++k)
            {
                if(ans < dp[j][k])
                    ans = dp[j][k];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
