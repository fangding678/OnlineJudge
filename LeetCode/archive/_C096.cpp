#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if(n == 0) {
            return 0;
        }
        vector<int> dp(n+1, 0);
        int i, j;
        dp[0] = 1;
        dp[1] = 1;
        for(i=2; i<=n ; ++i) {
            for(j=0; j<i; ++j) {
                dp[i] += dp[j]*dp[i-j-1];
            }
        }
        return dp[n];
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
