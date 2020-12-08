#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1 && n==1) {
            return 1;
        }
        vector<vector<int>> ans(m, vector<int>(n, 1));
        ans[0][0] = 0;
        for(int i=1; i<m; ++i) {
            for(int j=1; j<n; ++j) {
                ans[i][j] = ans[i-1][j] + ans[i][j-1];
            }
        }
        return ans[m-1][n-1];
    }
};

int func()
{
    Solution S;
    cout <<S.uniquePaths(4, 3)<< endl;
    return 0;
}
