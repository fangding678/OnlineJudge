#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        if(n <= 1) {
            return res;
        }
        for(int i=2; i<=n; ++i) {
            res = countAndSay(res);
        }
        return res;
    }
    string countAndSay(string & s) {
        int cnt = 1;
        size_t i;
        string ts;
        string res;
        char t = s[0];
        for(i=1; i<s.size(); ++i) {
            if(t == s[i]) {
                ++cnt;
            }
            else {
                stringstream ss;
                ss<<cnt;
                ss>>ts;
                res += ts + t;
                cnt = 1;
                t = s[i];
            }
        }
        stringstream ss;
        ss<<cnt<<t;
        ss>>ts;
        res += ts;
        return res;
    }
};

int func()
{
    Solution S;
    cout<<S.countAndSay(5)<<endl;
    return 0;
}
