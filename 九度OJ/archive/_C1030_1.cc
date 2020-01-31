//背包问题还是很不清晰，，需要多练习……

#include <iostream>
#include <algorithm>

using namespace std;

struct Bg
{
    int h;
    int l;
    int t;
    bool operator < (const Bg &A) const
    {
        return (t<A.t || (t==A.t && h<A.h));
    }
}bg[31];
int dp[101];
int main()
{
    int n;
    int i,j;
    int m;
    while(cin>>n)
    {
        if(n<0)
            break;
        m = 0;
        for(i=1; i<=n; ++i)
        {
            cin>>bg[i].h>>bg[i].l>>bg[i].t;
            if(m < bg[i].t)
                m = bg[i].t;
        }
        sort(bg+1, bg+n+1);
        for(i=0; i<=m; ++i)
            dp[i] = 0;
        for(i=1; i<=n; ++i)
        {
            for(j=bg[i].t; j>=bg[i].l; --j)
            {
                if(dp[j] < dp[j-bg[i].l] + bg[i].h)
                {
                    dp[j] = dp[j-bg[i].l] + bg[i].h;
                }
            }
            for(j=bg[i].t + 1; j<=m; ++j)
            {
                if(dp[j] < dp[bg[i].t])
                {
                    dp[j] = dp[bg[i].t];
                }
            }
        }
        cout<<dp[m]<<endl;
    }
    return 0;
}



/*
for(i=1; i<=n; ++i)
{
    for(j=m; j>=bg[i].l; --j)
    {
        if(dp[j] < dp[j-bg[i].l] + bg[i].h)
        {
            dp[j] = dp[j-bg[i].l] + bg[i].h;
        }
    }
}
*/
