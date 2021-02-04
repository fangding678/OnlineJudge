//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size();
        if (rows < 1) {
            return;
        }
        int cols = board[0].size();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                int alive_cnt = 0;
                for (int ii = max(0, i-1); ii <= min(rows-1, i+1); ++ii) {
                    for (int jj = max(0, j-1); jj <= min(cols-1, j+1); ++jj) {
                        if (board[ii][jj] > 0) {
                            alive_cnt += 1;
                        }
                    }
                }
                if (board[i][j] == 1) {
                    alive_cnt -= board[i][j];
                    if (alive_cnt < 2 || alive_cnt > 3) {
                        board[i][j] = 2;
                    }
                } else {
                    if(alive_cnt == 3) {
                        board[i][j] = -1;
                    }
                }
            }
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] == -1) {
                    board[i][j] = 1;
                } else if (board[i][j] == 2) {
                    board[i][j] = 0;
                }
            }
        }
    }
};

void func() {
    Solution solution;
    string str = "ads";
    cout << str << endl;
}

