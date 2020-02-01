#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static void search(vector<vector<char>>& grid, vector<vector<bool>>& flag, int i, int j, const int M, const int N) {
        flag[i][j] = false;
        if (i > 0 && grid[i-1][j] == '1' && flag[i-1][j]) {
            search(grid, flag, i-1, j, M, N);
        }
        if (i < M-1 && grid[i+1][j] == '1' && flag[i+1][j]) {
            search(grid, flag, i+1, j, M, N);
        }
        if (j > 0 && grid[i][j-1] == '1' && flag[i][j-1]) {
            search(grid, flag, i, j-1, M, N);
        }
        if (j < N-1 && grid[i][j+1] == '1' && flag[i][j+1]) {
            search(grid, flag, i, j+1, M, N);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        if (grid.size() == 0 || grid[0].size() == 0) {
            return ans;
        }
        const int M = grid.size();
        const int N = grid[0].size();
        vector<vector<bool >> flag(M, vector<bool >(N, true));
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == '1' && flag[i][j] == true) {
                    ans += 1;
                    search(grid, flag, i, j, M, N);
                }
            }
        }
        return ans;
    }
};

