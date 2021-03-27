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
        sumArr.clear();
        int t = 0;
        sumArr.push_back(t);
        for (auto n : nums) {
            t += n;
            sumArr.push_back(t);
        }
    }

    void update(int index, int val) {

    }

    int sumRange(int left, int right) {
        sumArr[right+1] - sumArr[left];
    }

private:
    vector<int> sumArr;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

void func() {
    vector<int> vec{};
    NumArray numArray(vec);
    string str = "ads";
    cout << str << endl;
}

