//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        if (num < 1) {
            return false;
        }
        while (num % 2 == 0) {
            num /= 2;
        }
        while (num % 3 == 0) {
            num /= 3;
        }
        while (num % 5 == 0) {
            num /= 5;
        }
        return num == 1;
    }
};

void func() {
    Solution solution;
    cout << solution.isUgly(2) << endl;
    cout << solution.isUgly(6) << endl;
    cout << solution.isUgly(8) << endl;
    cout << solution.isUgly(14) << endl;
}

