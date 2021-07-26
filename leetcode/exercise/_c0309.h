//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> sellDp;
        vector<int> buyDp;
        int ans = 0;
        int sz = prices.size();
        if (sz < 2) {
            return 0;
        }
        sellDp.push_back(0);
        sellDp.push_back(max(0, prices[1] - prices[0]));
        ans = max(ans, sellDp[1]);
        buyDp.push_back(-prices[0]);
        buyDp.push_back(max(-prices[0], -prices[1]));
        for (int i = 2; i < sz; ++i) {
            buyDp.push_back(max(buyDp[i-1], sellDp[i-2] - prices[i]));
            sellDp.push_back(max(buyDp[i-1] + prices[i], sellDp[i-1]));
            ans = max(buyDp[i], ans);
            ans = max(sellDp[i], ans);
        }
        return ans;
    }
};

void func() {
    Solution solution;
    vector<int> v1{1,2,3,0,2};
    cout << solution.maxProfit(v1) << endl;
}

