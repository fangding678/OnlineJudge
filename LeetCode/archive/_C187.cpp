#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        if (s.size() < 10) {
            return ans;
        }
        set<string> st;
        set<string> st2;
        size_t len = s.size();
        for (size_t i = 0; i <= len-10; ++i) {
            string str = s.substr(i, 10);
            if (st.find(str) != st.end() && st2.find(str) == st2.end()) {
                ans.push_back(str);
                st2.insert(str);
            } else {
                st.insert(str);
            }
        }
        return ans;
    }
};

