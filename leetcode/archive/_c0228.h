//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (nums.empty()) {
            return ans;
        }
        int start = nums[0], end = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i-1] + 1 == nums[i]) {
                end = nums[i];
            } else {
                if (start != end) {
                    ans.push_back(to_string(start) + "->" + to_string(end));
                } else {
                    ans.push_back(to_string(start));
                }
                start = nums[i];
                end = nums[i];
            }
        }
        if (start != end) {
            ans.push_back(to_string(start) + "->" + to_string(end));
        } else {
            ans.push_back(to_string(start));
        }
        return ans;
    }
};

void func() {
    Solution solution;
    vector<int> v1{0,1,2,4,5,7};
    vector<int> v2{0,2,3,4,6,8,9};
    _print(solution.summaryRanges(v1));
    _print(solution.summaryRanges(v2));
}

