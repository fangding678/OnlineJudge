#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std;

//大牛妙解
//bool isMatch(const char *s, const char *p) {
//  assert(s && p);
//  if (*p == '\0') return *s == '\0';
//
//  // next char is not '*': must match current character
//  if (*(p+1) != '*') {
//    assert(*p != '*');
//    return ((*p == *s) || (*p == '.' && *s != '\0')) && isMatch(s+1, p+1);
//  }
//  // next char is '*'
//  while ((*p == *s) || (*p == '.' && *s != '\0')) {
//    if (isMatch(s, p+2)) return true;
//    s++;
//  }
//  return isMatch(s, p+2);
//}

class Solution {
public:
    bool isMatch(string s, string p) {
        if((s.size() == 0 && p.size() == 0) || s == p)
            return true;
        if(p.size() == 0)
            return false;
        int lens = s.length();
        int lenp = p.length();
        int js, jp;
        bool res;
        bool **dp = new bool*[lens+1];
        for(js=0; js<lens+1; ++js) {
            dp[js] = new bool[lenp+1];
            memset(dp[js], false, sizeof(bool)*(lenp+1));
        }
        dp[0][0] = true;
        for(jp=0; jp<lenp; ++jp) {
            if(p[jp] == '*') {
                if(jp < 1)
                    continue;
                if(jp > 0 && dp[0][jp-1])
                    dp[0][jp+1] = true;
                if(p[jp-1] != '.') {
                    for(js=0; js<lens; ++js) {
                        if(dp[js+1][jp] || dp[js+1][jp-1]
                           || (s[js]==p[jp-1] && dp[js][jp+1])) {
                            dp[js+1][jp+1] = true;
                        }
                    }
                }
                else {
                    js = 0;
                    while(jp > 0 && js < lens && !dp[js+1][jp-1] && !dp[js+1][jp])
                        ++js;
                    for(; js<lens; ++js) {
                        dp[js+1][jp+1] = true;
                    }
                }
            }
            else {
                for(js=0; js<lens; ++js) {
                    if(s[js] == p[jp] || p[jp] == '.')
                        dp[js+1][jp+1] = dp[js][jp];
                }
            }
        }
        res = dp[lens][lenp];
//        for(js=0; js<lens+1; ++js) {
//            for(jp=0; jp<lenp+1; ++jp)
//                cout<<dp[js][jp]<<'\t';
//            cout<<endl;
//        }
        for(js=0; js<lens+1; ++js) {
            delete[] dp[js];
        }
        delete[] dp;
        return res;
    }
};

int func()
{
    Solution S;
    cout<<S.isMatch("aab", "c*a*b")<<endl;
    return 0;
}

//ÍøÉÏ´óÅ£×ö·¨
class Solution2 {
public:
    bool isMatch(const char *s, const char *p) {
        int m = strlen(s), n = strlen(p);
        vector<vector<bool>> dp(m+1, vector<bool>(n+1,false));
        dp[0][0] = true;

        for(int i=0; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                if(p[j-1]!='.' && p[j-1]!='*') {
                    if(i>0 && s[i-1]==p[j-1] && dp[i-1][j-1])
                        dp[i][j] = true;
                }
                else if(p[j-1]=='.') {
                    if(i>0 && dp[i-1][j-1])
                        dp[i][j] = true;
                }
                else if(j>1) {  //'*' cannot be the 1st element
                    if(dp[i][j-1] || dp[i][j-2])  // match 0 or 1 preceding element
                        dp[i][j] = true;
                    else if(i>0 && (p[j-2]==s[i-1] || p[j-2]=='.') && dp[i-1][j]) // match multiple preceding elements
                        dp[i][j] = true;
                }
            }
        }
        return dp[m][n];
    }
};

// Time Limit Exceeded
class Solution1 {
public:
    bool isMatch(string s, string p) {
        if(s == p)
            return true;
        int lens = s.size();
        int lenp = p.size();
        return isMatchCore(s, p, lens, lenp, 0, 0);
    }
    bool isMatchCore(const string& str, const string& pattern, int& lens, int& lenp, int indexs, int indexp) {
        if(indexs == lens && indexp == lenp)
            return true;
        if(indexs != lens && indexp == lenp)
            return false;
        if(pattern[indexp+1] == '*') {
            if(pattern[indexp] == str[indexs] || (pattern[indexp] == '.' && lens != indexs)) {
                return isMatchCore(str, pattern, lens, lenp, indexs+1, indexp+2)
                    || isMatchCore(str, pattern, lens, lenp, indexs+1, indexp)
                    || isMatchCore(str, pattern, lens, lenp, indexs, indexp+2);
            }
            else {
                return isMatchCore(str, pattern, lens, lenp, indexs, indexp+2);
            }
        }
        if(str[indexs] == pattern[indexp] || (pattern[indexp] == '.' && indexs != lens))
            return isMatchCore(str, pattern, lens, lenp, indexs+1, indexp+1);
        return false;
    }
};

