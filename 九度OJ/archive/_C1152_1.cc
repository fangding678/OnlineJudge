#include <iostream>

using namespace std;

int main()
{
    int dp[1001],v[101],p[101];
    int i,j,c,n;
    while(cin>>c>>n)
    {
        for(i=0; i<n; ++i)
            cin>>v[i]>>p[i];
        for(i=0; i<=c; ++i)
            dp[i] = 0;
        for(i=0; i<n; ++i)
        {
            for(j=c; j>=v[i];  --j)
            {
                if(dp[j] < dp[j-v[i]] + p[i])
                    dp[j] = dp[j-v[i]] + p[i];
            }
        }
        cout<<dp[c]<<endl;
    }
    return 0;
}
