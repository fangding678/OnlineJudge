#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        size_t lens = s.size(), lenp = p.size();
        size_t i = 0, j = 0, ipre, jpre;
        bool flag = false;
        while(i < lens) {
            if(j < lenp && (s[i] == p[j] || p[j] == '?')) {
                ++i;
                ++j;
            }
            else if(p[j] == '*') {
                jpre = j;
                ++j;
                ipre = i;
                flag = true;
            }
            else if(flag) {
                i = ipre + 1;
                j = jpre;
            }
            else {
                return false;
            }
        }
        while(j<lenp && p[j]=='*') {
            ++j;
        }
        return j==lenp;
    }
};

//Memory Limit Exceeded
class Solution2 {
public:
    bool isMatch(string s, string p) {
        size_t lens = s.size(), lenp = p.size();
        size_t i, j;
        bool **dp = new bool*[lens + 1];
        for(i=0; i<=lens; ++i) {
            dp[i] = new bool[lenp + 1];
            memset(dp[i], false, sizeof(bool) * (lenp+1));
        }
        dp[0][0] = true;
        for(j=0; j<lenp; ++j) {
            if(p[j] == '*') {
                i = 0;
                while(i<=lens && !dp[i][j]) ++i;
                for(; i<=lens; ++i) {
                    dp[i][j+1] = true;
                }
            }
            else {
                for(i=0; i<lens; ++i) {
                    if(s[i] == p[j] || p[j] == '?') {
                        dp[i+1][j+1] = dp[i][j];
                    }
                }
            }
        }
        return dp[lens][lenp];
    }
};

//Time Limit Exceeded
class Solution1 {
public:
    bool isMatch(string s, string p) {
        return isMatch(s,p,0,0);
    }
    bool isMatch(string s, string p, size_t a, size_t b) {
        size_t lens = s.size(), lenp = p.size();
        while(b < lenp && a < lens) {
            if(s[a] == p[b] || p[b] == '?') {
                ++a;
                ++b;
            }
            else if(p[b] == '*') {
                return isMatch(s, p, a, b+1) || isMatch(s, p, a+1, b);
            }
            else {
                return false;
            }
        }
        if(a == lens && b == lenp) {
            return true;
        }
        if(a == lens) {
            while(b < lenp && p[b] == '*') ++b;
            if(b == lenp) {
                return true;
            }
        }
        return false;
    }
};

int func()
{
    Solution S;
    string s = "aa";
    string p = "*";
    cout << S.isMatch(s, p) << endl;
    return 0;
}
