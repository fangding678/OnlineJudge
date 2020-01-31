#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        const int M = dungeon.size();
        const int N = dungeon[0].size();
        int dp[M][N];
        dp[M-1][N-1] = max(0, -dungeon[M-1][N-1]);
        int a1, a2, b1, b2;
        for (int i = N-2; i >= 0; --i) {
            dp[M-1][i] = max(0, dp[M-1][i+1] - dungeon[M-1][i]);
        }
        for (int i = M-2; i >= 0; --i) {
            dp[i][N-1] = max(0, dp[i+1][N-1] - dungeon[i][N-1]);
            for (int j = N-2; j >= 0; --j) {
                dp[i][j] = max(0, min(dp[i][j+1], dp[i+1][j]) - dungeon[i][j]);
            }
        }
        return 1 + dp[0][0];
    }

    // Time Limit Exceeded
    int calculateMinimumHP1(vector<vector<int>>& dungeon) {
        int t = dungeon[0][0];
        int ans = DFS(dungeon, t, min(0, t), 0, 0) + 1;
        return ans;
    }

    int DFS(vector<vector<int>>& dungeon, int x, int y, int i, int j) {
        if (i == dungeon.size()-1 && j == dungeon[0].size()-1) {
            return -y;
        }
        int xx, yy;
        int r1, r2;
        if (j == dungeon[0].size()-1) {
            xx = x + dungeon[i+1][j];
            yy = min(y, xx);
            return DFS(dungeon, xx, yy, i+1, j);
        } else if (i == dungeon.size()-1) {
            xx = x + dungeon[i][j+1];
            yy = min(y, xx);
            return DFS(dungeon, xx, yy, i, j+1);
        } else {
            xx = x + dungeon[i+1][j];
            yy = min(y, xx);
            r1 = DFS(dungeon, xx, yy, i+1, j);
            xx = x + dungeon[i][j+1];
            yy = min(y, xx);
            r2 = DFS(dungeon, xx, yy, i, j+1);
        }
        return min(r1, r2);
    }
};

