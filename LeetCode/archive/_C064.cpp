#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int i, j, t;
        vector<int> vec1(grid[0]);
        vector<int> vec(n, 0);
        for(i=1; i<n; ++i) {
            vec1[i] += vec1[i-1];
        }
        t = grid[0][0];
        for(i=1; i<m; ++i) {
            t += grid[i][0];
            vec[0] = t;
            for(j=1; j<n; ++j) {
                vec[j] = min(vec[j-1], vec1[j]) + grid[i][j];
            }
            swap(vec, vec1);
        }
        return vec1[n-1];
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
