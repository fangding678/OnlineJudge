//
// Created by fangding on 2020-02-01.
//

#ifndef ONLINEJUDGE__C215_H
#define ONLINEJUDGE__C215_H
#include <string>
using namespace std;

class Solution {
public:
    void swap(vector<int>& nums, int s, int e) {
        int t = nums[s];
        nums[s] = nums[e];
        nums[e] = t;
    }
    int getIndex(vector<int>& nums, int s, int e) {
        while (s < e) {
            while (s < e && nums[s] > nums[e]) --e;
            swap(nums, s, e);
            while (s < e && nums[s] >= nums[e]) ++s;
            swap(nums, s, e);
        }
        return s;
    }
    int findKthLargest(vector<int>& nums, int k) {
        --k;
        int len = nums.size();
        int s = 0, e = len-1;
        int ind = getIndex(nums, s, e);
        while (ind != k) {
            if (ind == k) {
                break;
            } else if (ind > k) {
                e = ind - 1;
            } else if (ind < k) {
                s = ind + 1;
            }
            ind = getIndex(nums, s, e);
        }
        return nums[ind];
    }
};

void func() {
    string res = "ads";
    Solution solution;
    vector<int> vec{3,2,3,1,2,4,5,5,6};
    vector<int> vec1{3,2,1,5,6,4};
    cout << solution.findKthLargest(vec, 4) << endl;
    cout << solution.findKthLargest(vec1, 2) << endl;
}

#endif //ONLINEJUDGE__C215_H
