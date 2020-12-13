//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
#include <set>
using namespace std;

// timeout
class Solution1 {
public:
    bool isNear(set<int> &st, int t) {
        int ii = 0;
        int num;
        for (auto s : st) {
            if (0 == ii) {
                num = s;
                ++ii;
                continue;
            }
            if (s <= long(t) + num) {
                return true;
            } else {
                num = s;
            }
        }
        return false;
    }
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
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
        if (st.size() < k || isNear(st, t)) {
            return true;
        }
        for (int i = k; i < nums.size(); ++i) {
            st.insert(nums[i]);
            if (st.size() < k+1 || isNear(st, t)) {
                return true;
            }
            st.erase(st.find(nums[i-k]));
        }
        return false;
    }
};

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.size() <= 1 || k < 1) {
            return false;
        }
        return false;
    }
};

void func() {
    Solution solution;
    vector<int> v1{1,2,3,1};
    vector<int> v2{1,0,1,1};
    vector<int> v3{1,5,9,1,5,9};
    vector<int> v4{-3,3,-6};
    vector<int> v5{-2147483648,2147483647};
    vector<int> v6{2147483646,2147483647};
    cout << solution.containsNearbyAlmostDuplicate(v1, 3, 0) << endl;
    cout << solution.containsNearbyAlmostDuplicate(v2, 1, 2) << endl;
    cout << solution.containsNearbyAlmostDuplicate(v3, 2, 3) << endl;
    cout << solution.containsNearbyAlmostDuplicate(v4, 2, 3) << endl;
    cout << solution.containsNearbyAlmostDuplicate(v5, 1, 1) << endl;
    cout << solution.containsNearbyAlmostDuplicate(v6, 3, 3) << endl;
    int tmp = 10000;
    cout << tmp << " " << long(tmp) * tmp << " " << long(tmp) * tmp * tmp + tmp << endl;
}

