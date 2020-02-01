#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Solution {
private:
    vector<vector<bool>> mark;
    int m, n;
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        if(m == 0) {
            return false;
        }
        n = board[0].size();
        int i, j;
        vector<bool> mar;
        for(i=0; i<m; ++i) {
            for(j=0; j<n; ++j) {
                mar.push_back(false);
            }
            mark.push_back(mar);
        }
        for(i=0; i<m; ++i) {
            for(j=0; j<n; ++j) {
                if(exist(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool exist(vector<vector<char>> & board, string & word, size_t t, int i, int j) {
        if(t == word.size()) {
            return true;
        }
        if(board[i][j] != word[t]) {
            return false;
        }
        if(t == word.size()-1) {
            return true;
        }
        mark[i][j] = true;
        if(i>0 && mark[i-1][j]==false && exist(board, word, t+1, i-1, j)) {
            return true;
        }
        if(i<m-1 && mark[i+1][j]==false && exist(board, word, t+1, i+1, j)) {
            return true;
        }
        if(j>0 && mark[i][j-1]==false && exist(board, word, t+1, i, j-1)) {
            return true;
        }
        if(j<n-1 && mark[i][j+1]==false && exist(board, word, t+1, i, j+1)) {
            return true;
        }
        mark[i][j] = false;
        return false;
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
