#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string> sword(wordDict.begin(), wordDict.end());
        int slen = s.size();
        bool dp[slen+1];
        for (int i = 0; i <= slen; ++i) {
            dp[i] = false;
        }
        vector<int> vec;
        dp[0] = true;
        vec.push_back(0);
        for (int i=1; i<=slen; ++i) {
            for (int j=i; j>0; --j) {
                if ((sword.find(s.substr(j-1, i-j+1)) != sword.end()) && dp[j-1]) {
                    dp[i] = true;
                    vec.push_back(i);
                    break;
                }
            }
        }
        vector<string> res;
        if (dp[slen]) {
            search(s, sword, vec, "", 0, res);
        }
        return res;
    }
    void search(string &s, set<string> &sword, vector<int> &vec, string tmp, int index, vector<string> &res) {
        if (index == vec.size()-1) {
            res.push_back(tmp.substr(0, tmp.size()-1));
            return;
        }
        int b = vec[index];
        int e;
        while (index < vec.size()-1) {
            e = vec[index+1];
            index++;
            if (sword.find(s.substr(b, e-b)) != sword.end()) {
                string ttmp = tmp + s.substr(b, e-b) + " ";
                search(s, sword, vec, ttmp, index, res);
            }
        }
    }
};


