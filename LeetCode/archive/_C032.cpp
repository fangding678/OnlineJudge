#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        size_t ans = 0;
        stack<pair<size_t, bool>> st;
        size_t i;
        for(i=0; i<s.size(); ++i) {
            if(s[i] == '(') {
                st.push(make_pair(i, false));
            }
            else {
                if(st.empty() || st.top().second == true) {
                    st.push(make_pair(i, true));
                }
                else {
                    st.pop();
                    if(st.empty()) {
                        ans = i+1;
                    }
                    else {
                        ans = max(ans, i - st.top().first);
                    }
                }
            }
        }
        return ans;
    }
};

int func()
{
    Solution S;
    string s = "()(()";
    cout << S.longestValidParentheses(s) << endl;
    return 0;
}
