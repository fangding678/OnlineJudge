#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int ans = nums[0];
        int dp1[nums.size()], dp2[nums.size()];
        dp1[0] = nums[0], dp2[0] = nums[0];
        int num;
        for (int i = 1; i < nums.size(); ++i) {
            num = nums[i];
            if (num>=0) {
                dp1[i] = max(dp1[i-1] * num, num);
                dp2[i] = min(dp2[i-1] * num, num);
            } else {
                dp1[i] = max(num, dp2[i-1] * num);
                dp2[i] = min(num, dp1[i-1] * num);
            }
        }
        for (int j = 0; j < nums.size(); ++j) {
            if (dp1[j] > ans) {
                ans = dp1[j];
            }
        }
        return ans;
    }
};

