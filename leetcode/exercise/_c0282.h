//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
using namespace std;

class Solution {
public:
    void addOperatorsHelper(string &num, int start, long target, string &ta, long ct, long pre, vector<string> &ans) {
        if (num.size() == start && target == ct && !ta.empty()) {
            ans.push_back(ta);
            return;
        }
//        cout << start << "\t" << ta << endl;
        for (int i = start+1; i <= num.size(); ++i) {
            if (num[start] == '0' && i > start+1) {
                break;
            }
            string st = num.substr(start, i-start);
            long t = stol(st);
            if (ta.empty()) {
                addOperatorsHelper(num, i, target, st, t, t, ans);
            } else {
                string tmps = ta;
                addOperatorsHelper(num, i, target, tmps.append("-").append(st), ct - t, -t, ans);
                tmps = ta;
                addOperatorsHelper(num, i, target, tmps.append("+").append(st), ct + t, t, ans);
                tmps = ta;
                addOperatorsHelper(num, i, target, tmps.append("*").append(st), (ct - pre) + pre * t, pre * t, ans);
            }
//            cout << "====" << endl;
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        string ta;
        addOperatorsHelper(num, 0, target, ta, 0L, 0L, ans);
        return ans;
    }
};

void func() {
    Solution solution;
    _print(solution.addOperators("123", 6));
    _print(solution.addOperators("232", 8));
    _print(solution.addOperators("105", 5));
    _print(solution.addOperators("00", 0));
    _print(solution.addOperators("3456237490", 9191));
}

