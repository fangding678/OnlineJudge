#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int ans = 0;
        if (nums.size() == 0) {
            return ans;
        } else if (nums.size() == 1) {
            return max(ans, nums[0]);
        }
        ans = max(nums[0], nums[1]);
        vector<int> dp(nums);
        dp[1] = max(dp[0], dp[1]);
        for (int i = 2; i < nums.size(); ++i) {
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

