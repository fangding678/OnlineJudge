#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


class Solution {
public:
    int countPrimes(int n) {
        int d = int(sqrt(n));
        vector<bool> isPrimes(n+1, true);
        isPrimes[0] = false;
        isPrimes[1] = false;
        int t, ans = 0;
        for (int i = 2; i <= d; ++i) {
            if (!isPrimes[i]) {
                continue;
            }
            ans += 1;
            t = n / i;
            for (int j = 2; j <= t; ++j) {
                isPrimes[i*j] = false;
            }
        }
        for (int k = d+1; k < n; ++k) {
            if (isPrimes[k]) {
                ans += 1;
            }
        }
        return ans;
    }
};
