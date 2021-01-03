//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 1) {
            return false;
        }
        while (n > 1) {
            if (n & 1) {
                return false;
            }
            n = n >> 1;
        }
        return true;
    }
};

void func() {
    Solution solution;
    cout << solution.isPowerOfTwo(16) << endl;
}

