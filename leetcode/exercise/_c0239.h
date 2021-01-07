//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        if (nums.empty()) {
            return ans;
        }
        deque<int> deq;
        int tm;
        deq.push_back(0);
        for (int i = 1; i < k; ++i) {
            tm = deq.back();
            while (!deq.empty() && nums[i] >= nums[tm]) {
                deq.pop_back();
                if (!deq.empty()) {
                    tm = deq.back();
                }
            }
            deq.push_back(i);
        }
//        cout << "=====" << endl;
//        _print(deq);
        ans.push_back(nums[deq.front()]);
        for (int i = k; i < nums.size(); ++i) {
            int j;
            while (!deq.empty()) {
                j = deq.back();
                if (nums[j] <= nums[i]) {
                    deq.pop_back();
                } else {
                    break;
                }
            }
            deq.push_back(i);
            j = deq.front();
            while (i - j >= k) {
                deq.pop_front();
                j = deq.front();
            }
            ans.push_back(nums[deq.front()]);
        }
        return ans;
    }
};

void func() {
    Solution solution;
    vector<int> vec1{1,3,-1,-3,5,3,6,7};
    vector<int> vec2{1, -1};
    vector<int> vec3{9,10,9,-7,-4,-8,2,-6};
    _print(solution.maxSlidingWindow(vec1, 3));
    _print(solution.maxSlidingWindow(vec2, 1));
    _print(solution.maxSlidingWindow(vec3, 5));
}

