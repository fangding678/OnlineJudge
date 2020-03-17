//
// Created by fangding on 2020-03-17.
//

#ifndef ONLINEJUDGE__C012_H
#define ONLINEJUDGE__C012_H

class Solution {
public:
    double Power(double base, int exponent) {
        if (0.0 == base) {
            return 0.0;
        } else if (0 == exponent) {
            return 1;
        }
        double ans = base;
        bool isNeg = false;
        if (exponent < 0) {
            exponent = -exponent;
            isNeg = true;
        }
        for (int i = 1; i < exponent; ++i) {
            ans *= base;
        }
        if (isNeg) {
            ans = 1 / ans;
        }
        return ans;
    }
};

void func() {
    Solution solution;
    cout << solution.Power(2.2, -2) << endl;
}

#endif //ONLINEJUDGE__C012_H
