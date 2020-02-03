//
// Created by fangding on 2020-02-02.
//

#ifndef ONLINEJUDGE__C18_10_H
#define ONLINEJUDGE__C18_10_H

class Change {
public:
    int countChanges(vector<string> dic, int n, string s, string t) {
        if (s.size() != t.size()) {
            return -1;
        }
        set<string> sdic(dic.begin(), dic.end());
        map<string, int> mdic1, mdic2;
        mdic1[s] = 0;
        mdic2[t] = 0;
        fillDic(sdic, mdic1, s);
        fillDic(sdic, mdic2, t);
        int ans = n+1;
        for (auto &d1 : mdic1) {
            if (mdic2.find(d1.first) != mdic2.end()) {
                ans = min(ans, mdic1[d1.first]+mdic2[d1.first]);
            }
        }
        if (ans > n) {
            ans = -1;
        }
        return ans;
    }

    void fillDic(set<string> &sdic, map<string, int> &mdic1, string &s) {
        if (mdic1.find(s) != mdic1.end()) {
            for (string ti : sdic) {
                if (canTran(ti, s)) {
                    if (mdic1.find(ti) == mdic1.end() || mdic1[s] + 1 < mdic1[ti]) {
                        mdic1[ti] = mdic1[s] + 1;
                        fillDic(sdic, mdic1, ti);
                    }
                }
            }
        }
    }

    bool canTran(string &s1, string &s2) {
        if (s1.size() != s2.size()) {
            return false;
        }
        int diff = 0;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                ++diff;
            }
        }
        return 1 == diff;
    }
};

void func() {
    vector<string> A{"vvz","bbaa","f","bbba","bbaa","baoa","btoa","bbba","dcki","bbbb","ge","atoj","baaa","btoj","ae"};
    Change change;
    cout << change.countChanges(A, 15,"atoj", "bbbb") << endl;
}

#endif //ONLINEJUDGE__C18_10_H
