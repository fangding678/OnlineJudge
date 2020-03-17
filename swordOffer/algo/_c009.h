//
// Created by fangding on 2020-03-10.
//

#ifndef ONLINEJUDGE__C001_H
#define ONLINEJUDGE__C001_H

class Solution {
public:
    int jumpFloorII(int number) {
        if (number <= 2) {
            return number;
        }
        return 2 * jumpFloorII(number-1);
    }
};

void func() {
    Solution solution;
    cout << solution.jumpFloorII(3) << endl;
}

#endif //ONLINEJUDGE__C001_H
