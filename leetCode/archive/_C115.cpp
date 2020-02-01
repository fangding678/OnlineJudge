#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        int i, j;
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(i=0; i<=m; ++i) {
            dp[i][0] = 1;
        }
        for(i=1; i<=m; ++i) {
            for(j=1; j<=n; ++j) {
                if(s[i-1] == t[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[m][n];
    }
};

int func()
{
    Solution S;
    string s = "c";
    string t = "b";
    cout << S.numDistinct(s, t) << endl;
    return 0;
}
