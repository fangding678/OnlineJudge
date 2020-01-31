#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int ans = 0;
        int len = prices.size();
        if (k < 1 || len < 2) {
            return ans;
        }
        if (k >= len / 2) {
            for (int i = 1; i < len; ++i) {
                if (prices[i] > prices[i-1]) {
                    ans += prices[i] - prices[i-1];
                }
            }
            return ans;
        }
        vector<vector<int>> dp(k+1, vector<int>(len, 0));
        int t;
        for (int i = 1; i < k+1; ++i) {
            t = -prices[0];
            for (int j = 1; j < len; ++j) {
                dp[i][j] = max(dp[i][j-1], t + prices[j]);
                t = max(dp[i-1][j-1] - prices[j], t);
            }
        }
        return dp[k][len-1];
    }
};

