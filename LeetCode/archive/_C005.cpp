#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        if(s == "")
            return res;
        int startpos = 0;
        int resl = 1;
        int i, b, e, t;
        int len = s.size();
        for(i=1; i<len; ++i) {
            b = i;
            e = i-1;
            t = 0;
            while(--b>=0 && ++e<len) {
                if(s[b] == s[e]) {
                    t += 2;
                }
                else {
                    break;
                }
            }
            ++b;
            if (t > resl) {
                resl = t;
                startpos = b;
            }
            b = i;
            e = i;
            t = 1;
            while(--b>=0 && ++e<len) {
                if(s[b] == s[e]) {
                    t += 2;
                }
                else {
                    break;
                }
            }
            ++b;
            if (t > resl) {
                resl = t;
                startpos = b;
            }
        }
        res = s.substr(startpos, resl);
        return res;
    }
};

int func()
{
    Solution S;
    string s = "";
    cout<<S.longestPalindrome(s)<<endl;
    return 0;
}
