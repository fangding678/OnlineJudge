#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col) {
        int i,j, irow, jcol;
        for(i = 0; i<9; ++i) {
            if(i != row && board[i][col] == board[row][col]) {
                return false;
            }
            if(i != col && board[row][i] == board[row][col]) {
                return false;
            }
        }
        irow = row/3 * 3 + 3;
        jcol = col/3 * 3 + 3;
        for(i=row/3 * 3; i < irow; ++i) {
            for(j=col/3 * 3 ; j < jcol; ++j) {
                if(i == row && j == col) {
                    continue;
                }
                if(board[i][j] == board[row][col])
                    return false;
            }
        }
        return true;
    }

    bool solveSudoku(vector<vector<char>>& board, size_t row, size_t col) {
        if(col >= 9) {
            ++row;
            col = 0;
        }
        if(row >= 9) {
            return true;
        }
        char c = board[row][col];
        if(c <= '9' && c >= '0') {
            return solveSudoku(board, row, col+1);
        }
        for(int i=1; i<=9; ++i) {
            board[row][col] = '0' + i;
            if(isValid(board, row, col)) {
                if(solveSudoku(board, row, col+1)) {
                    return true;
                }
            }
        }
        board[row][col] = c;
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solveSudoku(board, 0, 0);
    }
};

int func()
{
    vector<string> str = {"..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",
    ".98...3..","...8.3.2.","........6","...2759.."};
    vector<vector<char>> vec;
    size_t i, j;
    for(i=0; i<str.size(); ++i) {
        vector<char> vc;
        for(j=0; j<str[i].size(); ++j) {
            vc.push_back(str[i][j]);
        }
        vec.push_back(vc);
    }
    Solution S;
    S.solveSudoku(vec);
    for(i=0; i<vec.size(); ++i) {
        for(j=0; j<vec[i].size(); ++j) {
            cout<<vec[i][j];
        }
        cout<<endl;
    }
    return 0;
}
