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
        len = nums.size();
        if (len > 0) {
            tree = vector<int>(2 * len, 0);
            for (int i = len; i < 2 * len; ++i) {
                tree[i] = nums[i-len];
            }
            for (int i = len-1; i > 0; --i) {
                tree[i] = tree[i*2] + tree[i*2+1];
            }
        }
    }

    void update(int index, int val) {
        index += len;
        int diff = val - tree[index];
        while (index > 0) {
            tree[index] += diff;
            index /= 2;
        }
    }

    int sumRange(int left, int right) {
        left += len;
        right += len;
        int sum = 0;
        while (left <= right) {
            if (left % 2 == 1) {
                sum += tree[left];
                left++;
            }
            if (right % 2 == 0) {
                sum += tree[right];
                right--;
            }
            left /= 2;
            right /= 2;
        }
        return sum;
    }

    vector<int> getTree() {
        return tree;
    }

private:
    int len;
    vector<int> tree;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

void func() {
    vector<int> v1{1, 3, 5};
    NumArray numArray(v1);
    cout << numArray.sumRange(0, 2) << endl;
    _print(numArray.getTree());
    numArray.update(1, 2);
    _print(numArray.getTree());
    cout << numArray.sumRange(0, 2) << endl;
}

