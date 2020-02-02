//
// Created by fangding on 2020-02-02.
//

#ifndef ONLINEJUDGE__C18_3_H
#define ONLINEJUDGE__C18_3_H

class NextElement {
public:
    vector<int> findNext(vector<int> A, int n) {
        vector<int> res(n, -1);
        for (int i = n-2; i >= 0; --i) {
            res[i] = _search(A, i, n);
        }
        return res;
    }

    int _search(vector<int>& A, int start, int n) {
        int tmp = A[start];
        for (int i = start+1; i < n; ++i) {
            if (tmp < A[i]) {
                A[i-1] = tmp;
                return A[i];
            } else {
                A[i-1] = A[i];
            }
        }
        A[n-1] = tmp;
        return -1;
    }
};

void func() {
    vector<int> A{11,13,10,5,12,21,3};
    NextElement nextElement;
    _print(nextElement.findNext(A, 7));
}

#endif //ONLINEJUDGE__C18_3_H
