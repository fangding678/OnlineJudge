//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums) {
        ans.clear();
        int t = 0;
        ans.push_back(t);
        for (auto num : nums) {
            t += num;
            ans.push_back(t);
        }
//        _print(ans);
    }

    int sumRange(int left, int right) {
        return ans[right+1] - ans[left];
    }
    vector<int> ans;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

void func() {
    vector<int> nums{-2, 0, 3, -5, 2, -1};
    NumArray* obj = new NumArray(nums);
    cout << obj->sumRange(0,2) << endl;
    cout << obj->sumRange(2,5) << endl;
    cout << obj->sumRange(0,5) << endl;
}

