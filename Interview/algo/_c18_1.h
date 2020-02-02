//
// Created by fangding on 2020-02-01.
//

#ifndef ONLINEJUDGE__C18_1_H
#define ONLINEJUDGE__C18_1_H

class UnusualAdd {
public:
    int addAB(int A, int B) {
        // write code here
        int x = A & B;
        int y = A ^ B;
        if (0 == x) {
            return y;
        }
        return addAB(y, x << 1);
    }
};

void func() {
    cout << "running begin..." << endl;
    UnusualAdd unusualAdd;
    cout << unusualAdd.addAB(12, 23) << endl;
    cout << "running end..." << endl;
}

#endif //ONLINEJUDGE__C18_1_H
