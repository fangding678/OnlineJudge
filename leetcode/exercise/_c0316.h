//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        string res = "";
        int indexArr[26];
        bool visited[26];
        for(auto i = 0 ; i < s.length(); ++i) {
            int ind = s[i] - 'a';
            indexArr[ind] = i;
            visited[ind] = false;
        }
        for(auto i = 0 ; i < s.length(); ++i) {
            int ind = s[i] - 'a';
            while (!st.empty() && st.top() > s[i] && indexArr[st.top() - 'a'] > i && !visited[ind]) {
                visited[st.top() - 'a'] = false;
                st.pop();
            }
            if (!visited[ind]) {
                st.push(s[i]);
                visited[ind] = true;
            }
        }
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

void func() {
    Solution solution;
    string str1 = "bcabc";
    string str2 = "cbacdcbc";
    cout << solution.removeDuplicateLetters(str1) << endl;
    cout << solution.removeDuplicateLetters(str2) << endl;
}

