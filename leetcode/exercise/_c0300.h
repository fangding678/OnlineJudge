//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
using namespace std;

class Solution {
public:
    int lengthOfLIS1(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int ans = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        int maxL = 0;
        for (auto num : nums) {
            int lo = 0, hi = maxL;
            while (lo < hi) {
                int mi = (hi-lo)/2 + lo;
                if (dp[mi] < num) {
                    lo = mi+1;
                } else {
                    hi = mi;
                }
            }
            dp[lo] = num;
            if (lo == maxL) {
                maxL += 1;
            }
        }
        return maxL;
    }
};

void func() {
    Solution solution;
    vector<int> v1{10,9,2,5,3,7,101,18};
    vector<int> v2{0,1,0,3,2,3};
    vector<int> v3{7,7,7,7,7,7,7};
    vector<int> v4{1,3,6,7,9,4,10,5,6};
    cout << solution.lengthOfLIS(v1) << endl;
    cout << solution.lengthOfLIS(v2) << endl;
    cout << solution.lengthOfLIS(v3) << endl;
    cout << solution.lengthOfLIS(v4) << endl;
}

