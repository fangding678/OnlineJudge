//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        ans.push_back(1);
        int t = 1;
        int len = nums.size();
        for (int i = 1; i < len; ++i) {
            t *= nums[i-1];
            ans.push_back(t);
        }
//        _print(ans);
        t = nums[len-1];
        for (int i = len-2; i >= 0 ; --i) {
            ans[i] = t * ans[i];
            t *= nums[i];
        }
        return ans;
    }
};

void func() {
    Solution solution;
    vector<int> vec{1,2,3,4};
    _print(solution.productExceptSelf(vec));
}

