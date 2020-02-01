#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        int ans = 1;
        if(nums.size() == 1) {
            return ans;
        }
        unordered_set<int> st(nums.begin(), nums.end());
        for(auto i : nums) {
            if(st.find(i) == st.end()) {
                continue;
            }
            ans = max(prev_next_search(st, i), ans);
        }
        return ans;
    }
    int prev_next_search(unordered_set<int> &st, int n) {
        int res = 0;
        int t = n-1;
        while(st.find(t) != st.end()) {
            st.erase(t);
            ++res;
            --t;
        }
        t = n;
        while(st.find(t) != st.end()) {
            st.erase(t);
            ++res;
            ++t;
        }
        return res;
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
