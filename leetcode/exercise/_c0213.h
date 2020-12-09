//
// Created by fangding on 2020-02-01.
//

#ifndef ONLINEJUDGE__C213_H
#define ONLINEJUDGE__C213_H
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int ans;
        int len = nums.size();
        if (len == 0) {
            return 0;
        } else if (len == 1) {
            return nums[0];
        } else if (len == 2) {
            return max(nums[0], nums[1]);
        }
        vector<int> dp1(len, 0);
        dp1[0] = nums[0];
        dp1[1] = nums[0];
        for (int i = 2; i < len-1; ++i) {
            dp1[i] = max(dp1[i-2] + nums[i], dp1[i-1]);
        }
        ans = dp1[len-2];
        dp1[0] = 0;
        dp1[1] = nums[1];
        for (int i = 2; i < len; ++i) {
            dp1[i] = max(dp1[i-2] + nums[i], dp1[i-1]);
        }
        ans = max(ans, dp1[len-1]);
        return ans;
    }
};

void func() {
    vector<int> vec{1, 3, 5, 2, 4};
    Solution solution;
    cout << solution.rob(vec) << endl;
}

#endif //ONLINEJUDGE__C213_H
