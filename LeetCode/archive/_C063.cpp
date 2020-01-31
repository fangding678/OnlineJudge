#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int i, j;
        if(m == 1 && n == 1)
            return !obstacleGrid[0][0];
        vector<vector<int>> ans(m, vector<int>(n, 1));
        ans[0][0] = 0;
        for(i=0; i<m; ++i) {
            if(obstacleGrid[i][0]) {
                break;
            }
            ans[i][0] = 1;
        }
        while(i < m) {
            ans[i][0] = 0;
            ++i;
        }
        for(i=0; i<n; ++i) {
            if(obstacleGrid[0][i]) {
                break;
            }
            ans[0][i] = 1;
        }
        while(i < n) {
            ans[0][i] = 0;
            ++i;
        }
        for(i=1; i<m; ++i) {
            for(j=1; j<n; ++j) {
                if(obstacleGrid[i][j]) {
                    ans[i][j] = 0;
                }
                else {
                    ans[i][j] = ans[i-1][j] + ans[i][j-1];
                }
            }
        }
        return ans[m-1][n-1];
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
