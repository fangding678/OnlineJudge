//
// Created by fangding on 2020-02-02.
//

#ifndef ONLINEJUDGE__C18_7_H
#define ONLINEJUDGE__C18_7_H

class LongestString {
public:
    int getLongest(vector<string> str, int n) {
        map<string, bool> mp;
        for (auto s : str) {
            mp.emplace(s, true);
        }
        sort(str.begin(), str.end(), [](string a, string b){
            return a.length() > b.length();
        });
        for (auto &s : str) {
            if (canBuild(mp, s)) {
                return s.length();
            }
        }
        return 0;
    }

    bool canBuild(map<string, bool> &mp, string &s) {
        if (s.length() == 1) {
            return mp.find(s) != mp.end();
        }
        for (int i = 1; i < s.length(); ++i) {
            string left = s.substr(0, i);
            string right = s.substr(i);
            if (mp.find(left) != mp.end() && (mp.find(right) != mp.end() || canBuild(mp, right))) {
                return true;
            }
        }
        return false;
    }
};

void func() {
    vector<string> A{"glhz","ddthddth","ddth","z","glh"};
    LongestString longestString;
    cout << longestString.getLongest(A, A.size()) << endl;
}

#endif //ONLINEJUDGE__C18_7_H
