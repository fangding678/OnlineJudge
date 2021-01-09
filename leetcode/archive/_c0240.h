//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
using namespace std;

class Solution {
public:
    bool searchMatrixHelper(vector<vector<int>>& matrix, int target, int row_s, int col_s, int row_e, int col_e) {
        if (row_s > row_e || col_s > col_e) {
            return false;
        } else if (row_s == row_e && col_s == col_e) {
            return target == matrix[row_s][col_s];
        }
        int row_m = (row_s + row_e) / 2;
        int col_m = (col_s + col_e) / 2;
        if (matrix[row_m][col_m] == target) {
            return true;
        } else if (matrix[row_m][col_m] < target) {
            return searchMatrixHelper(matrix, target, row_s, col_m+1, row_e, col_e) || searchMatrixHelper(matrix, target, row_m+1, col_s, row_e, col_m);
        } else {
            return searchMatrixHelper(matrix, target, row_s, col_s, row_m-1, col_e) || searchMatrixHelper(matrix, target, row_m, col_s, row_e, col_m-1);
        }
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int len1 = matrix.size();
        if (len1 < 1) {
            return false;
        }
        int len2 = matrix[0].size();
        if (len2 < 1) {
            return false;
        }
        return searchMatrixHelper(matrix, target, 0, 0, len1-1, len2-1);
    }
};

void func() {
    Solution solution;
    vector<vector<int>> matrix;
    vector<int> v1{1,4,7,11,15};
    vector<int> v2{2,5,8,12,19};
    vector<int> v3{3,6,9,16,22};
    vector<int> v4{10,13,14,17,24};
    vector<int> v5{18,21,23,26,30};
    matrix.push_back(v1);
    matrix.push_back(v2);
    matrix.push_back(v3);
    matrix.push_back(v4);
    matrix.push_back(v5);
    cout << solution.searchMatrix(matrix, 0) << endl;
    cout << solution.searchMatrix(matrix, 1) << endl;
    cout << solution.searchMatrix(matrix, 8) << endl;
    cout << solution.searchMatrix(matrix, 20) << endl;
    cout << solution.searchMatrix(matrix, 30) << endl;
    cout << solution.searchMatrix(matrix, 31) << endl;
}

