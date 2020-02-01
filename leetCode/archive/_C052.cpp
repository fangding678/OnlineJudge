#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    int ans;
public:
    int totalNQueens(int n) {
        vector<string> Q(n, string(n, '.'));
        ans = 0;
        totalNQueensCore(Q, n, 0);
        return ans;
    }
    bool isCheck(vector<string> & Q, int n, int x, int y) {
        for(int i=0; i<n; ++i) {
            if(Q[x][i] == 'Q' || Q[i][y] == 'Q') {
                return false;
            }
        }
        int tx = x+1, ty = y-1;
        while(tx < n && ty >= 0) {
            if(Q[tx][ty] == 'Q') {
                return false;
            }
            ++tx;
            --ty;
        }
        tx = x-1, ty = y+1;
        while(tx >= 0 && ty < n) {
            if(Q[tx][ty] == 'Q') {
                return false;
            }
            --tx;
            ++ty;
        }
        tx = x+1, ty = y+1;
        while(tx < n && ty < n) {
            if(Q[tx][ty] == 'Q') {
                return false;
            }
            ++tx;
            ++ty;
        }
        tx = x-1, ty = y-1;
        while(tx >= 0 && ty >= 0) {
            if(Q[tx][ty] == 'Q') {
                return false;
            }
            --tx;
            --ty;
        }
        return true;
    }
    void totalNQueensCore(vector<string> & Q, int n, int x) {
        if(x == n) {
            ++ans;
            return ;
        }
        for(int y=0; y<n; ++y) {
            if(isCheck(Q, n, x, y)) {
                Q[x][y] = 'Q';
                totalNQueensCore(Q, n, x+1);
                Q[x][y] = '.';
            }
        }
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
