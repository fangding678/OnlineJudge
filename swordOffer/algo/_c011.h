//
// Created by fangding on 2020-03-10.
//

#ifndef ONLINEJUDGE__C011_H
#define ONLINEJUDGE__C011_H

class Solution {
public:
    int  NumberOf1(int n) {
        int ans = 0;
        for (int i = 0; i<32; ++i) {
            ans += n & 1;
            n >>= 1;
        }
        return ans;
    }
};

void func() {
    Solution solution;
    cout << solution.NumberOf1(1) << endl;
}

#endif //ONLINEJUDGE__C011_H
