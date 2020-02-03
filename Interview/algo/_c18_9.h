//
// Created by fangding on 2020-02-02.
//

#ifndef ONLINEJUDGE__C18_9_H
#define ONLINEJUDGE__C18_9_H

class Middle {
public:
    vector<int> getMiddle(vector<int> A, int n) {
        vector<int> res;
        int tmp;
        if (n > 0) {
            res.push_back(A[0]);
        }
        for (int i = 1; i < n; ++i) {
            tmp = A[i];
            int j = i;
            while (j > 0 && tmp < A[j-1]) {
                A[j] = A[j-1];
                --j;
            }
            A[j] = tmp;
            res.push_back(A[i/2]);
        }
        return res;
    }
};

void func() {
    vector<int> A{1,2,3,4,5,6};
    Middle middle;
    _print(middle.getMiddle(A, 6));
}

#endif //ONLINEJUDGE__C18_9_H
