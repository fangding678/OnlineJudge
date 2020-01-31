#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = nums[0];
        int c = 1, i = 1;
        while (i < nums.size()) {
            if (c == 0) {
                ans = nums[i];
                ++c;
            } else {
                if (nums[i] != ans) {
                    --c;
                } else {
                    ++c;
                }
            }
            ++i;
        }
        return ans;
    }
};

