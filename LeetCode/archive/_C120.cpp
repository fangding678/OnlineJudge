#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int ans = INT_MAX;
        vector<vector<int>> dp;
        vector<int> d1(n, INT_MAX);
        vector<int> d2(n, INT_MAX);
        d1[0] = triangle[0][0];
        dp.push_back(d1);
        dp.push_back(d2);
        int i = 0, j, k;
        for(j=1; j<n; ++j) {
            dp[1-i][0] = dp[i][0] + triangle[j][0];
            for(k=1; k<j; ++k) {
                dp[1-i][k] = min(dp[i][k], dp[i][k-1]) + triangle[j][k];
            }
            dp[1-i][k] = dp[i][k-1] + triangle[j][k];
            i = 1-i;
        }
        for(j=0; j<n; ++j) {
            ans = min(ans, dp[i][j]);
        }
        return ans;
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
