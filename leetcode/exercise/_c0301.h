//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
using namespace std;

class Solution {
public:
    void dfs(int index, int leftCount, int rightCount, int leftRemoveCount, int rightRemoveCount, string path, string &s, set<string> &ans) {
        if (index == s.size()) {
            if (leftRemoveCount==0 && rightRemoveCount==0) {
                ans.insert(path);
            }
            return;
        }
//        cout << "path1=" << path << endl;
        if (s[index] == '(') {
            if (leftRemoveCount > 0) {
                dfs(index+1, leftCount, rightCount, leftRemoveCount-1, rightRemoveCount, path, s, ans);
            }
            path += s[index];
            dfs(index+1, leftCount+1, rightCount, leftRemoveCount, rightRemoveCount, path, s, ans);
        } else if (s[index] == ')') {
            if (rightRemoveCount > 0) {
                dfs(index+1, leftCount, rightCount, leftRemoveCount, rightRemoveCount-1, path, s, ans);
            }
            if (rightCount < leftCount) {
                path += s[index];
                dfs(index+1, leftCount, rightCount+1, leftRemoveCount, rightRemoveCount, path, s, ans);
            }
        } else {
            path += s[index];
            dfs(index+1, leftCount, rightCount, leftRemoveCount, rightRemoveCount, path, s, ans);
        }
//        cout << "path2=" << path << endl;
    }

    vector<string> removeInvalidParentheses(string s) {
        set<string> ans;
        int leftRemoveCount = 0, rightRemoveCount = 0;
        for (auto c : s) {
            if (c == '(') {
                ++leftRemoveCount;
            } else if (c == ')') {
                if (leftRemoveCount == 0) {
                    ++rightRemoveCount;
                } else {
                    --leftRemoveCount;
                }
            }
        }
        string path;
        dfs(0, 0, 0, leftRemoveCount, rightRemoveCount, path, s, ans);
        return vector<string>(ans.begin(), ans.end());
    }
};

void func() {
    Solution solution;
    _print(solution.removeInvalidParentheses("()())()"));
    _print(solution.removeInvalidParentheses("(a)())()"));
    _print(solution.removeInvalidParentheses(")("));
}

