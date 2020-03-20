//
// Created by fangding on 2020-03-19.
//

#ifndef ONLINEJUDGE__C019_H
#define ONLINEJUDGE__C019_H

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> list;
        int len1 = matrix.size();
        if (0 == len1 || 0 == matrix[0].size()) {
            return list;
        }
        int len2 = matrix[0].size();
        int up = 0, down = len1-1, left = 0, right = len2-1;
        while (true) {
            for (int i = left; i <= right; ++i) {
                list.push_back(matrix[up][i]);
            }
            if (++up > down) {
                break;
            }
            for (int i = up; i <= down; ++i) {
                list.push_back(matrix[i][right]);
            }
            if (--right < left) {
                break;
            }
            for (int i = right; i >= left; --i) {
                list.push_back(matrix[down][i]);
            }
            if (--down < up) {
                break;
            }
            for (int i = down; i >= up; --i) {
                list.push_back(matrix[i][left]);
            }
            if (++left > right) {
                break;
            }
        }
        return list;
    }
};

void func() {
    Solution solution;
    vector<vector<int>> vec;
    vector<int> v1{1,2,3,4};
    vector<int> v2{11,12,13,14};
    vector<int> v3{21,22,23,24};
    vec.push_back(v1);
    vec.push_back(v2);
    vec.push_back(v3);
    _print(v1);
    _print(v2);
    _print(v3);
    _print(solution.printMatrix(vec));
}
#endif //ONLINEJUDGE__C019_H
