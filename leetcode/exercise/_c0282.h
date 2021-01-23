//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
using namespace std;

class Solution {
public:
    void addOperatorsHelper(string &num, int target, int left, string &ta, vector<string> &ans) {
        if (num.empty() && target == 0 && !ta.empty()) {
            ans.push_back(ta);
            return;
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        string ta;
        int left = 0;
        addOperatorsHelper(num, target, left, ta, ans);
        return ans;
    }
};

void func() {
    Solution solution;
    _print(solution.addOperators("123", 6));
}

