//
// Created by fangding on 2020-02-03.
//

#ifndef ONLINEJUDGE__18_13_H
#define ONLINEJUDGE__18_13_H

class AlphaMatrix {
public:
    int findAlphaMatrix(vector<int> dic, int n) {
        int s = 0;
        for (int k = 0; k < dic.size(); ++k) {
            dic[k] %= n;
        }
        int i = 0, j = 0;
    }
};

void func() {
    vector<string> A{"aaa","aaa","aaa","bb","bb"};
    AlphaMatrix alphaMatrix;
    _print(alphaMatrix.findAlphaMatrix(A, 5));
}

#endif //ONLINEJUDGE__18_13_H
