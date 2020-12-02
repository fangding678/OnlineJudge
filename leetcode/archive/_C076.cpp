#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Solution {
    const int N = 256;
public:
    string minWindow(string s, string t) {
        string ans = "";
        if(t.size() == 0) {
            return ans;
        }
        int len = s.size();
        int a[N];
        memset(a, 0, sizeof(a));
        int start = 0;
        int l = len + 1;
        int b=0, e=0;
        for(auto c : t) {
            a[c]++;
        }
        while(b<=e && e<len) {
            if(isCheck(a)) {
                do {
                    ++a[s[b]];
                    ++b;
                } while(isCheck(a));
                if(l > e-b+1) {
                    start = b-1;
                    l = e-b+1;
                }
            }
            else {
                do {
                    --a[s[e]];
                    ++e;
                } while(e<len && (!isCheck(a)));
                if(isCheck(a) && l > e-b) {
                    start = b;
                    l = e-b;
                }
            }
        }
        if(isCheck(a)) {
            do {
                ++a[s[b]];
                ++b;
            } while(b<=e && isCheck(a));
            if(l > e-b+1) {
                start = b-1;
                l = e-b+1;
            }
        }
        if(l > len) {
            return ans;
        }
        ans = s.substr(start, l);
        return ans;
    }
    bool isCheck(int a[]) {
        for(int i=0; i<N; ++i) {
            if(a[i] > 0) {
                return false;
            }
        }
        return true;
    }
};

int func()
{
    Solution S;
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout<<S.minWindow(s, t)<<endl;
    return 0;
}
