#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s1[102],s2[102];
    int dp[102][102];
    int len1,len2;
    int i,j,k;
    while(cin>>s1>>s2)
    {
        len1 = strlen(s1);
        len2 = strlen(s2);
        for(k=1; k<102; ++k)
        {
            dp[k][0] = dp[0][k] = 0;
        }
        for(i=0; i<len1; ++i)
        {
            for(j=0; j<len2; ++j)
            {
                if(s1[i] == s2[j])
                    dp[i+1][j+1] = dp[i][j] + 1;
                else
                {
                    dp[i+1][j+1] = dp[i+1][j] > dp[i][j+1] ? dp[i+1][j] : dp[i][j+1];
                }
            }
        }
        cout<<dp[len1][len2]<<endl;
    }
    return 0;
}
