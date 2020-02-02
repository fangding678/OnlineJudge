//
// Created by fangding on 2020-02-02.
//

#ifndef ONLINEJUDGE__C18_8_H
#define ONLINEJUDGE__C18_8_H

class Substr {
public:
    vector<bool> chkSubStr(vector<string> p, int n, string s) {
        set<string> st;
        vector<bool> res;
        int ll = 0;
        for (auto &t : p) {
            if (t.length() > ll) {
                ll = t.length();
            }
        }
        for (int i = 0; i < ll; ++i) {
            for (int j = 0; j < s.size() - i; ++j) {
                st.insert(s.substr(j, i+1));
            }
        }
        for (string &t : p) {
            if (st.find(t) != st.end()) {
                res.push_back(true);
            } else {
                res.push_back(false);
            }
        }
        return res;
    }
};

void func() {
    vector<string> A{"a","b","c","d"};
    Substr substr;
    _print(substr.chkSubStr(A, 4, "abc"));
}

#endif //ONLINEJUDGE__C18_8_H
