//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include "__debug"
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.size() <= 1 || k < 1) {
            return false;
        }
        if (k > nums.size()) {
            k = nums.size();
        }
        set<int> st;
        for (int i = 0; i < k; ++i) {
            st.insert(nums[i]);
        }
        if (st.size() < k) {
            return true;
        }
        for (int i = k; i < nums.size(); ++i) {
            st.insert(nums[i]);
            if (st.size() < k+1) {
                return true;
            }
            st.erase(st.find(nums[i-k]));
        }
        return false;
    }
};

void func() {
    Solution solution;
    vector<int> v1{1,2,3,1,2,3};
    vector<int> v2{1,2,3,1};
    vector<int> v3{99, 99};
    cout << solution.containsNearbyDuplicate(v1, 3) << endl;
    cout << solution.containsNearbyDuplicate(v2, 2) << endl;
    cout << solution.containsNearbyDuplicate(v3, 2) << endl;
}

