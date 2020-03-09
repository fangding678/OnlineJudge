//
// Created by fangding on 2020-02-03.
//

#ifndef ONLINEJUDGE__C18_11_H
#define ONLINEJUDGE__C18_11_H

class SubMatrix {
public:
    int maxSubMatrix(vector<vector<int> > mat, int n) {
        int ans = min(1, n);
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < n; ++j) {
                for (int k = 1; k <= min(i, j); ++k) {
                    bool flag = true;
                    if (mat[i][j-k] != mat[i-k][j] || mat[i-k][j] != mat[i][j]) {
                        break;
                    } else {
                        for (int l = 1; l <= k; ++l) {
                            if (mat[i-k][j-l] != mat[i-l][j-k] || mat[i-k][j-l] != mat[i][j]) {
                                flag = false;
                                break;
                            }
                        }
                    }
                    if (flag) {
                        ans = max(ans, k+1);
                    }
                }
            }
        }
        return ans;
    }
};

void func() {
//    vector<vector<int>> A;
//    vector<int> v1{1,1,1}, v2{1,0,1}, v3{1,1,1};
    vector<vector<int>> A;
    vector<int> v1{1,1,1,0,0}, v2{1,1,1,0,1}, v3{0,0,0,0,0}, v4{1,0,1,1,0}, v5{1,0,0,0,1};
    A.push_back(v1);
    A.push_back(v2);
    A.push_back(v3);
    A.push_back(v4);
    A.push_back(v5);
    SubMatrix subMatrix;
    cout << subMatrix.maxSubMatrix(A, 5) << endl;
}

#endif //ONLINEJUDGE__C18_11_H
//1,1,1,0,0
//1,1,1,0,1
//0,0,0,0,0
//1,0,1,1,0
//1,0,0,0,1
