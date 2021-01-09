//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        int ans = 0;
        int t, a = n, b;
        long m = 1;
        while (a) {
            a = n / m / 10;
            t = n / m % 10;
            b = n % m;
            cout << "a=" << a << ", t=" << t << ", b=" << b << ", m=" << m << endl;
            if (t == 0) {
                ans += a * m;
            } else if (t == 1) {
                ans += a * m + b + 1;
            } else {
                ans += (a+1) * m;
            }
            m *= 10;
        }
        return ans;
    }
};

void func() {
    Solution solution;
    cout << solution.countDigitOne(0) << endl;
    cout << solution.countDigitOne(13) << endl;
    cout << solution.countDigitOne(1000000000) << endl;
}

