//
// Created by fangding on 2020-03-10.
//

#ifndef ONLINEJUDGE__C001_H
#define ONLINEJUDGE__C001_H

class Solution {
public:
    int rectCover(int number) {
        if (number <= 3) {
            return number;
        }
        return rectCover(number-1) + rectCover(number-2);
    }
};

void func() {
    Solution solution;
    cout << solution.rectCover(2) << endl;
}

#endif //ONLINEJUDGE__C001_H
