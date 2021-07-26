//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
using namespace std;

class Solution {
public:
    // https://www.bilibili.com/video/av45180542
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if (1 == n) {
            return nums[0];
        } else if (2 == n) {
            return nums[0] * nums[1] + max(nums[0], nums[1]);
        }
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        for (int len = 1; len <= n; ++len) {
            for (int i = 1; i <= n-len+1; ++i) {
                int j = i + len -1;
                for (int k = i; k <= j; ++k) {
                    dp[i][j] = max(dp[i][j], dp[i][k-1] + dp[k+1][j] + nums[k] * nums[i-1] * nums[j+1]);
                }
            }
        }
        return dp[1][n];
    }

    int maxCoins_error(vector<int>& nums) {
        if (1 == nums.size()) {
            return nums[0];
        } else if (2 == nums.size()) {
            return nums[0] * nums[1] + max(nums[0], nums[1]);
        }
        int tmp = nums[0] * nums[1] * nums[2];
        int ind = 1;
        for (int i = 2; i < nums.size() - 1; ++i) {
            int tmp2 = nums[i-1] * nums[i] * nums[i+1];
            if (tmp2 < tmp) {
                ind = i;
                tmp = tmp2;
            }
        }
        nums.erase(nums.begin()+ind);
        return tmp + maxCoins_error(nums);
    }
};

void func() {
    Solution solution;
    vector<int> nums1{3,1,5,8}; // 167
    vector<int> nums2{9,76,64,21}; // 116718
    cout << solution.maxCoins(nums1) << endl << endl;
    cout << solution.maxCoins(nums2) << endl;
}

