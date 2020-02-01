#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> sword(wordDict.begin(), wordDict.end());
        int slen = s.size();
        bool dp[slen+1];
        for (int i = 0; i <= slen; ++i) {
            dp[i] = false;
        }
        dp[0] = true;
        for (int i=1; i<=slen; ++i) {
            for (int j=i; j>0; --j) {
                if ((sword.find(s.substr(j-1, i-j+1)) != sword.end()) && dp[j-1]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[slen];
    }

    bool wordBreak_time(string s, vector<string>& wordDict) {
        int slen = s.size();
        for (auto iter = wordDict.cbegin(); iter != wordDict.cend(); ++iter) {
            if(s == *iter) {
                return true;
            } else if (slen > (*iter).size() && (*iter) == s.substr(0, (*iter).size())) {
                if (wordBreak(s.substr((*iter).size()), wordDict)) {
                    return true;
                }
            }
        }
        return false;
    }
};


