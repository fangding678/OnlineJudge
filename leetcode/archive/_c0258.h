//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        if (num < 10) {
            return num;
        }
        int ans = 0;
        while (num) {
            ans += num % 10;
            num /= 10;
        }
        return addDigits(ans);
    }
};

void func() {
    Solution solution;
    cout << solution.addDigits(38) << endl;
}

