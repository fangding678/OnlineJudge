//
// Created by fangding on 2020-02-03.
//

#ifndef ONLINEJUDGE__C18_11_H
#define ONLINEJUDGE__C18_11_H

class SubMatrix {
public:
    int maxSubMatrix(vector<vector<int> > mat, int n) {
        // write code here
    }
};

void func() {
    vector<vector<int>> A;
    vector<int> v1{1,1,1}, v2{1,0,1}, v3{1,1,1};
    A.push_back(v1);
    A.push_back(v2);
    A.push_back(v3);
    SubMatrix subMatrix;
    cout << subMatrix.maxSubMatrix(A, 3) << endl;
}

#endif //ONLINEJUDGE__C18_11_H
