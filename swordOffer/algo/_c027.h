//
// Created by fangding on 2020-03-21.
//

#ifndef ONLINEJUDGE__C027_H
#define ONLINEJUDGE__C027_H

class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> ans;
        if (0 == str.size()) {
            return ans;
        }
        sort(str.begin(), str.end());
        string s = str;
        do {
            ans.push_back(s);
//            cout << "s : " << s << endl;
        } while (nextStr(s));
        return ans;
    }

    bool nextStr(string &str) {
        int len = str.size();
        int i = len-2;
        for (; i >= 0 && str[i] >= str[i+1]; --i);
        if (-1 == i) {
            return false;
        }
        int j;
        for (j = len-1; j > 0 && str[j] <= str[i]; --j);
        char tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        for (int a = i+1, b = len-1; a<b; ++a, --b) {
            tmp = str[a];
            str[a] = str[b];
            str[b] = tmp;
        }
        return true;
    }
};

void func() {
    Solution solution;
    vector<string> ans = solution.Permutation("abcd");
    _print(ans);
}

#endif //ONLINEJUDGE__C027_H
