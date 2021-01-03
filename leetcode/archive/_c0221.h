//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
using namespace std;

class Solution {
public:
    int min3(int a, int b, int c) {
        return min(a, min(b, c));
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0;
        int height = matrix.size();
        if (height < 1) {
            return ans;
        }
        int width = matrix[0].size();
        if (width < 1) {
            return ans;
        }
        vector<vector<int>> dp1(height, vector<int>(width, 0));
        for (int j = 0; j < width; ++j) {
            dp1[0][j] = matrix[0][j] == '0' ? 0 : 1;
            ans = max(ans, dp1[0][j]);
        }
        for (int i = 1; i < height; ++i) {
            dp1[i][0] = matrix[i][0] == '0' ? 0 : 1;
            ans = max(ans, dp1[i][0]);
            for (int j = 1; j < width; ++j) {
                if (matrix[i][j] == '0') {
                    dp1[i][j] = 0;
                } else {
                    dp1[i][j] = 1 + min3(dp1[i-1][j-1], dp1[i-1][j], dp1[i][j-1]);
//                    cout << dp1[i][j] << "\n";
                    ans = max(ans, dp1[i][j]);
                }
            }
        }
//        _print(dp1);
        return ans * ans;
    }
};

void func() {
    Solution solution;
    string str = "ads";
    vector<vector<char>> matrix;
    matrix.push_back({'1','0','1','0','0'});
    matrix.push_back({'1','0','1','1','1'});
    matrix.push_back({'1','1','1','1','1'});
    matrix.push_back({'1','0','0','1','0'});
    _print(matrix);
    cout << solution.maximalSquare(matrix) << endl;
    cout << endl;
}

