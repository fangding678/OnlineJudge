#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0) {
            return ;
        }
        int n = matrix[0].size();
        int i, j;
        vector<pair<int, int>> vp;
        for(i=0; i<m; ++i) {
            for(j=0; j<n; ++j) {
                if(matrix[i][j] == 0) {
                    vp.push_back(pair<int, int>(i, j));
                }
            }
        }
        for(auto pp : vp) {
            setZero(matrix, pp.first, pp.second);
        }
    }
    void setZero(vector<vector<int>>& matrix, int i, int j) {
        int k;
        for(k=0; k<matrix[0].size(); ++k) {
            matrix[i][k] = 0;
        }
        for(k=0; k<matrix.size(); ++k) {
            matrix[k][j] = 0;
        }
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
