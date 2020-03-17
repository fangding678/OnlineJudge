//
// Created by fangding on 2020-03-10.
//

#ifndef ONLINEJUDGE__C001_H
#define ONLINEJUDGE__C001_H

class Solution {
public:
    int Fibonacci(int n) {
        if (0 == n) {
            return 0;
        }
        int ans = 1;
        int t = 0;
        int tt = t;
        for (int i = 1; i < n; ++i) {
            tt = ans;
            ans += t;
            t = tt;
        }
        return ans;
    }
};

void func() {
    Solution solution;
    cout << solution.Fibonacci(5) << endl;
}

#endif //ONLINEJUDGE__C001_H
