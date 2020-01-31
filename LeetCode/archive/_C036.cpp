#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudokuCore(vector<vector<char>>& board, int x1, int y1, int x2, int y2) {
        vector<bool> b(10, false);
        char c;
        for(int i=x1; i<=x2; ++i) {
            for(int j=y1; j<=y2; ++j) {
                c = board[i][j];
                if(c > '9' && c < '0') {
                    continue;
                }
                if(b[c-'0'])
                    return false;
                else
                    b[c-'0'] = true;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        if(isValidSudokuCore(board, 0,0,8,0) && isValidSudokuCore(board, 0,1,8,1) &&
           isValidSudokuCore(board, 0,2,8,2) && isValidSudokuCore(board, 0,3,8,3) &&
           isValidSudokuCore(board, 0,4,8,4) && isValidSudokuCore(board, 0,5,8,5) &&
           isValidSudokuCore(board, 0,6,8,6) && isValidSudokuCore(board, 0,7,8,7) &&
           isValidSudokuCore(board, 0,8,8,8) && isValidSudokuCore(board, 0,0,0,8) &&
           isValidSudokuCore(board, 1,0,1,8) && isValidSudokuCore(board, 2,0,2,8) &&
           isValidSudokuCore(board, 3,0,3,8) && isValidSudokuCore(board, 4,0,4,8) &&
           isValidSudokuCore(board, 5,0,5,8) && isValidSudokuCore(board, 6,0,6,8) &&
           isValidSudokuCore(board, 7,0,7,8) && isValidSudokuCore(board, 8,0,8,8) &&
           isValidSudokuCore(board, 0,0,2,2) && isValidSudokuCore(board, 0,3,2,5) &&
           isValidSudokuCore(board, 0,6,2,8) && isValidSudokuCore(board, 3,0,5,2) &&
           isValidSudokuCore(board, 3,3,5,5) && isValidSudokuCore(board, 3,6,5,8) &&
           isValidSudokuCore(board, 6,0,8,2) && isValidSudokuCore(board, 6,3,8,5) &&
           isValidSudokuCore(board, 6,6,8,8) ) {
                return true;
        }
        return false;
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
