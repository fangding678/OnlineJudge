#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int T,M;
    int i,j;
    int dp[1001],c[101],value[101];
    while(cin>>T>>M)
    {
        memset(dp, 0, sizeof(dp));
        for(i=0; i<M; ++i)
            cin>>c[i]>>value[i];
        for(i=0; i<M; ++i)
        {
            for(j=T; j>=c[i]; j--)
            {
                dp[j] = max(dp[j], dp[j-c[i]] + value[i]);
            }
        }
        cout<<dp[T]<<endl;
    }
    return 0;
}
