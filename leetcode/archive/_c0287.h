//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int t = nums[0];
        while (t != nums[t]) {
            nums[0] = nums[t];
            nums[t] = t;
            t = nums[0];
        }
        return t;
    }
};

void func() {
    Solution solution;
    vector<int> v1{1,3,4,2,2};
    vector<int> v2{3,1,3,4,2};
    vector<int> v3{1,1,2};
    cout << solution.findDuplicate(v1) << endl;
    cout << solution.findDuplicate(v2) << endl;
    cout << solution.findDuplicate(v3) << endl;
}

