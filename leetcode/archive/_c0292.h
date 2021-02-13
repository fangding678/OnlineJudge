//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        return n & 3;
    }
};

void func() {
    Solution solution;
    cout << solution.canWinNim(4) << endl;
    cout << solution.canWinNim(5) << endl;
    cout << solution.canWinNim(6) << endl;
    cout << solution.canWinNim(7) << endl;
    cout << solution.canWinNim(8) << endl;
}

