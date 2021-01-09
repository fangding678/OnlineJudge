//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int t = 0;
        vector<int> ans;
        for (auto num : nums) {
            t ^= num;
        }
        int i = 1;
        while (!(i & t)) {
            i <<= 1;
        }
        t = i;
        int a = 0, b = 0;
        for (auto num : nums) {
            if (num & t) {
                a ^= num;
            } else {
                b ^= num;
            }
        }
        ans.push_back(a);
        ans.push_back(b);
        return ans;
    }
};

void func() {
    Solution solution;
    vector<int> nums{1,2,1,3,2,5};
    _print(solution.singleNumber(nums));
}

