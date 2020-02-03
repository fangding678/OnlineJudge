//
// Created by fangding on 2020-02-03.
//

#ifndef ONLINEJUDGE__C18_12_H
#define ONLINEJUDGE__C18_12_H

class SubMatrix {
public:
    int sumOfSubMatrix(vector<vector<int> > mat, int n) {
        // write code here
    }
};

void func() {
    vector<vector<int>> A;
    vector<int> v1{1,2,-3}, v2{3,4,-5}, v3{-5,-6,-7};
    A.push_back(v1);
    A.push_back(v2);
    A.push_back(v3);
    SubMatrix subMatrix;
    cout << subMatrix.sumOfSubMatrix(A, 3) << endl;
}

#endif //ONLINEJUDGE__C18_12_H
