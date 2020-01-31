#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        size_t n = matrix.size();
        size_t i, j;
        int t;
        for(i=0; i<n/2; ++i) {
            for(j=i; j<n-i-1; ++j) {
                t = matrix[i][j];
                matrix[i][j] = matrix[n-j-1][i];
                matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
                matrix[j][n-i-1] = t;
            }
        }
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
