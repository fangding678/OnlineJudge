#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        const int len = s.size();
        if(len <= 1) {
            return 0;
        }
        vector<int> dp(len+1, len);
        bool mark[len][len];
        fill_n(&mark[0][0], len*len, false);
        int i, j;
        for(i=0; i<=len; ++i) {
            dp[i] = i-1;
        }
        for(i=1; i<len; ++i) {
            for(j=i; j>=0; --j) {
                if(s[i] == s[j] && (i-j < 2 || mark[j+1][i-1])) {
                    mark[j][i] = true;
                    dp[i+1] = min(dp[i+1], dp[j]+1);
                }
            }
        }
        return dp[len];
    }
};


class Solution1 {
public:
    int minCut(string s) {
        int len = s.size();
        if(len <= 1) {
            return 0;
        }
        vector<int> dp(len+1, len);
        dp[1] = 0;
        dp[0] = -1;
        int i, j;
        for(i=2; i<=len; ++i) {
            dp[i] = dp[i-1] + 1;
            for(j=1; j<i; ++j) {
                if(isCheck(s, j-1, i-1)) {
                    dp[i] = min(dp[i], dp[j-1] + 1);
                }
            }
        }
        return dp[len];
    }
    bool isCheck(string &s, int low, int high) {
        while(low < high) {
            if(s[low] != s[high]) {
                return false;
            }
            ++low;
            --high;
        }
        return true;
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
