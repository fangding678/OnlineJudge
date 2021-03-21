//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.size() < 1) {
            return;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> tmp(n+1, 0);
        sumMatrix.push_back(tmp);
        for (int i = 0; i < m; ++i) {
            vector<int> tmpVec;
            int t = 0;
            tmpVec.push_back(t);
            for (int j = 0; j < n; ++j) {
                t += matrix[i][j];
                tmpVec.push_back(t + sumMatrix[i][j+1]);
            }
            sumMatrix.push_back(tmpVec);
        }
        for (int i = 0; i < matrix.size(); ++i) {
            _print(matrix[i]);
        }
        cout << "============" << endl;
        for (int i = 0; i < sumMatrix.size(); ++i) {
            _print(sumMatrix[i]);
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sumMatrix[row2+1][col2+1] + sumMatrix[row1][col1] - sumMatrix[row1][col2+1] - sumMatrix[row2+1][col1];
    }

private:
    vector<vector<int>> sumMatrix;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

void func() {
    vector<vector<int>> matrix;
    matrix.push_back({3, 0, 1, 4, 2});
    matrix.push_back({5, 6, 3, 2, 1});
    matrix.push_back({1, 2, 0, 1, 5});
    matrix.push_back({4, 1, 0, 1, 7});
    matrix.push_back({1, 0, 3, 0, 5});

    NumMatrix* obj = new NumMatrix(matrix);
    cout << obj->sumRegion(2, 1, 4, 3) << endl;
    cout << obj->sumRegion(1, 1, 2, 2) << endl;
    cout << obj->sumRegion(1, 2, 2, 4) << endl;
}

