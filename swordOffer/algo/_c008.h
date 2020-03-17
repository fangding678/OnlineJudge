//
// Created by fangding on 2020-03-10.
//

#ifndef ONLINEJUDGE__C001_H
#define ONLINEJUDGE__C001_H

class Solution {
public:
    int jumpFloor(int number) {
        if (2 >= number) {
            return number;
        }
        return jumpFloor(number-1) + jumpFloor(number-2);
    }
};

void func() {
    Solution solution;
    cout << solution.jumpFloor(3) << endl;
}

#endif //ONLINEJUDGE__C001_H
