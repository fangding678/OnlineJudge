#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int i, j, k = n/2;
        int t = 1;
        for(i=0; i<k; ++i) {
            for(j=i; j<n-i; ++j) {
                ans[i][j] = t++;
            }
            for(j=i+1; j<n-i; ++j) {
                ans[j][n-i-1] = t++;
            }
            for(j=n-i-2; j>=i; --j) {
                ans[n-i-1][j] = t++;
            }
            for(j=n-i-2; j>i; --j) {
                ans[j][i] = t++;
            }
        }
        if((n&1) == 1) {
            ans[k][k] = t;
        }
        return ans;
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
