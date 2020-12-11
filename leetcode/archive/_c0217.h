//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include <unordered_set>
#include "__debug"
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for (auto n : nums) {
            if (st.find(n) == st.end()) {
                st.insert(n);
            } else {
                return true;
            }
        }
        return false;
    }
};

void func() {
    Solution solution;
    string str = "ads";
    cout << str << endl;
}

