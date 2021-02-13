//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int s = 0, e = 0;
        while (e < nums.size()) {
            if (nums[e] != 0) {
                nums[s++] = nums[e++];
            } else {
                ++e;
            }
        }
        while (s < nums.size()) {
            nums[s++] = 0;
        }
    }
};

void func() {
    Solution solution;
    vector<int> v1{0,1,0,3,12};
    solution.moveZeroes(v1);
}

