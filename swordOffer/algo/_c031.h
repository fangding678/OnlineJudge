//
// Created by fangding on 2020-03-29.
//

#ifndef ONLINEJUDGE__C031_H
#define ONLINEJUDGE__C031_H

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int ans = 0;
        if (n <= 0) {
            return ans;
        }
        int cur, low, high, base = 1;
        while (n >= base) {
            cur = (n / base) % 10;
            high = n / (base * 10);
            low = n % (base);
            if (cur > 1) {
                ans += (high + 1) * base;
            } else if (cur == 1) {
                ans += high * base + low + 1;
            } else {
                ans += high * base;
            }
            base *= 10;
        }
        return ans;
    }
};

void func() {
    Solution solution;
    cout << solution.NumberOf1Between1AndN_Solution(100) << endl;
}

#endif //ONLINEJUDGE__C031_H
