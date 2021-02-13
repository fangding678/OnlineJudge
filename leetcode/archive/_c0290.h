//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        size_t spos = 0;
        size_t epos;
        map<char, string> mp;
        map<string, char> mp2;
        vector<string> svec;
        while ((epos = s.find(" ", spos)) != string::npos) {
            svec.push_back(s.substr(spos, epos-spos));
            spos = epos+1;
        }
        svec.push_back(s.substr(spos));
        if (svec.size() != pattern.size()) {
            return false;
        }
        for (int i = 0; i < svec.size(); ++i) {
            if (mp.find(pattern[i]) == mp.end() && mp2.find(svec[i]) == mp2.end()) {
                mp.insert(std::pair<char, string>(pattern[i], svec[i]));
                mp2.insert(std::pair<string, char>(svec[i], pattern[i]));
            } else if (mp.find(pattern[i]) == mp.end() || mp2.find(svec[i]) == mp2.end()) {
                return false;
            } else if (mp[pattern[i]] != svec[i] || mp2[svec[i]] != pattern[i]) {
                return false;
            }
        }
        return true;
    }
};

void func() {
    Solution solution;
    cout << solution.wordPattern("aacb", "str str at at") << endl;
    cout << solution.wordPattern("aba", "dog cat cat") << endl;
}

