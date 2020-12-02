#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        int t = s3.size();
        if(t != m+n) {
            return false;
        }
        int i, j;
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        for(i=1; i<=m; ++i) {
            if(s1[i-1] != s3[i-1]) {
                break;
            }
            dp[i][0] = true;
        }
        for(i=1; i<=n; ++i) {
            if(s2[i-1] != s3[i-1]) {
                break;
            }
            dp[0][i] = true;
        }
        for(i=1; i<=m; ++i) {
            for(j=1; j<=n; ++j) {
                dp[i][j] = (dp[i-1][j]&&s1[i-1]==s3[i+j-1]) || (dp[i][j-1]&&s2[j-1]==s3[i+j-1]);
            }
        }
        return dp[m][n];
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
