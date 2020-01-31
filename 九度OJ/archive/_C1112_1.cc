#include <iostream>

using namespace std;

int main()
{
    int k,i,j;
    int a[26];
    int dp[26];
    int ans;
    while(cin>>k)
    {
        for(i=0; i<k; ++i)
        {
            cin>>a[i];
            dp[i] = 1;
        }
        for(i=1; i<=k; ++i)
        {
            for(j=0; j<i; ++j)
            {
                if(a[i] <= a[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        ans = dp[0];
        for(i=1; i<k; ++i)
        {
            if(dp[i] > ans)
                ans = dp[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
