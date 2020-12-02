#include <iostream>
#include <string>
#include <bitset>
#include <vector>

using namespace std;

class Solution {
public:
    bool isCheck(char c1, char c2) {
        if((c1=='1' && c2<='9' && c2>='1') || (c1=='2' && c2<='6' && c2>='1')) {
            return true;
        }
        return false;
    }
    int numDecodings(string s) {
        int i, len = s.size();
        if(len == 0) {
            return 0;
        }
        vector<int> dp(len+1, 1);
        if((s[0]>'9' || s[0]<'1') && (s[0]<'A' || s[0]>'Z')) {
            return 0;
        }
        for(i=2; i<=len; ++i) {
            if((s[i-1]>'9' || s[i-1]<'0') && (s[i-1]<'A' || s[i-1]>'Z')) {
                return 0;
            }
            if(s[i-1] == '0') {
                if(s[i-2] != '1' && s[i-2] != '2') {
                    return 0;
                }
                else {
                    dp[i] = dp[i-2];
                }
            }
            else if(isCheck(s[i-2], s[i-1])) {
                dp[i] = dp[i-1] + dp[i-2];
            }
            else {
                dp[i] = dp[i-1];
            }
        }
        return dp[len];
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
