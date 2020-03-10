//
// Created by fangding on 2020-03-10.
//

#ifndef ONLINEJUDGE__C001_H
#define ONLINEJUDGE__C001_H

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int m = array.size();
        int n = array[0].size();
        return Find(target, array, 0, 0, m-1, n-1);
    }

    bool Find(int target, vector<vector<int> > &array, int x1, int y1, int x2, int y2) {
        if (x1 > x2 || y1 > y2) {
            return false;
        }
        if (array[x1][y1] > target || array[x2][y2] < target) {
            return false;
        }
        if (x1 == x2 && y1 == y2 && array[x1][y1] != target) {
            return false;
        }
        cout << "x1: " << x1 << ", y1: " << y1 << endl;
        cout << "x2: " << x2 << ", y2: " << y2 << endl;
        int x = (x1+x2)/2;
        int y = (y1+y2)/2;
        cout << "x: " << x << ", y: " << y << endl;
        if (array[x][y] == target) {
            return true;
        } else if (array[x][y] > target) {
            return Find(target, array, x1, y1, x-1, y-1) || Find(target, array, x1, y, x-1, y2) || Find(target, array, x, y1, x2, y-1);
        } else {
            return Find(target, array, x+1, y+1, x2, y2) || Find(target, array, x+1, y1, x2, y) || Find(target, array, x1, y+1, x, y2);
        }
    }
};

void func() {
    vector<int> v1{1,2,3};
    vector<int> v2{4,5,8};
    vector<int> v3{5,7,9};
    vector<vector<int>> vec;
    vec.push_back(v1);
    vec.push_back(v2);
    vec.push_back(v3);
    Solution solution;
    cout << solution.Find(8, vec) << endl;
}

#endif //ONLINEJUDGE__C001_H
