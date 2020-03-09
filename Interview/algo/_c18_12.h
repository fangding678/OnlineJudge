//
// Created by fangding on 2020-02-03.
//

#ifndef ONLINEJUDGE__C18_12_H
#define ONLINEJUDGE__C18_12_H

class SubMatrix {
public:
    int sumOfSubMatrix(vector<vector<int> > mat, int n) {
        int ans = INT_MIN;
        int tmx = INT_MIN;
        vector<int> dp(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int l = 0; l < n; ++l) {
                dp[l] = 0;
            }
            for (int j = i; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    dp[k] += mat[j][k];
                }
                ans = max(ans, sumOfArr(dp, n));
                tmx = max(tmx, mat[i][j]);
            }
        }
        ans = max(ans, tmx);
        return ans;
    }

    int sumOfArr(vector<int> arr, int n) {
        int sum = 0, b = 0;
        for (int i = 0; i < n; ++i) {
            if (b > 0) {
                b += arr[i];
            } else {
                b = arr[i];
            }
            if (b > sum) {
                sum = b;
            }
        }
        return sum;
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
