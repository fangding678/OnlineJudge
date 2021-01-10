//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
using namespace std;

class Solution {
public:
    Solution() {
        int cnt = 1;
        uglyArr[cnt] = 1;
        int mi;
        int j = 1;
        int t, k;
        while (cnt < 1691) {
            mi = 2123366401;
            for (int i = j; i <= cnt; ++i) {
                k = uglyArr[i];
                t = uglyArr[cnt] - k;
                if (t < uglyArr[i] && mi - uglyArr[i] > uglyArr[i]) {
                    mi = uglyArr[i] * 2;
                    continue;
                }
                t -= uglyArr[i];
                if (t < uglyArr[i] && mi - uglyArr[i] - uglyArr[i] > uglyArr[i]) {
                    mi = uglyArr[i] * 3;
                    continue;
                }
                t -= uglyArr[i];
                t -= uglyArr[i];
                if (t < uglyArr[i] && mi - uglyArr[i] - uglyArr[i] > 3 * uglyArr[i]) {
                    mi = uglyArr[i] * 5;
                    j = i;
                    continue;
                }
            }
            ++cnt;
        }
    }
    int nthUglyNumber(int n) {
        return uglyArr[n];
    }

private:
    int uglyArr[1691];
};

void func() {
    Solution solution;
    cout << solution.nthUglyNumber(10) << endl;
    cout << solution.nthUglyNumber(1690) << endl;
}

