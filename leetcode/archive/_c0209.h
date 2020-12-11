//
// Created by fangding on 2020-01-31.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size();
        int res = len + 1;
        int tmp = 0;
        int sum = 0;
        int start = 0, end = 0;
        while (end < len) {
            sum += nums[end];
            tmp += 1;
            if (sum >= s) {
                while (start < end && sum - nums[start] >= s) {
                    sum -= nums[start];
                    tmp -= 1;
                    ++start;
                }
                res = min(res, tmp);
            }
            ++end;
        }
        if (res > len) {
            res = 0;
        }
        return res;
    }
};


void func() {
    Solution solution;
    int s = 15;
    vector<int> nums{2,3,1,1,1,1,1};
    cout << "res = " << solution.minSubArrayLen(s, nums) << endl;
}

