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
        int index = 1;
        uglyArr[index] = 1;
        int j = 1;
        while (index < 1691) {
            int mi = 2123366401;
            for (int i = j; i <= index; ++i) {
                for (int ii = 2; ii <= 5; ++ii) {
                   if (uglyArr[index] / ii < uglyArr[i] && mi / ii >= uglyArr[i]) {
                       mi = uglyArr[i] * ii;
                   }
                }
            }
            if (uglyArr[j] < uglyArr[index] / 5) {
                ++j;
            }
            ++index;
            uglyArr[index] = mi;
        }
    }
    int nthUglyNumber(int n) {
        return uglyArr[n];
    }

private:
    int uglyArr[1692];
};

void func() {
    Solution solution;
    cout << solution.nthUglyNumber(10) << endl;
    cout << solution.nthUglyNumber(347) << endl;
    cout << solution.nthUglyNumber(1690) << endl;
}

