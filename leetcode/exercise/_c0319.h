//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
using namespace std;

class Solution {
public:
    int bulbSwitch(int n) {
        int ans = sqrt(n);
        return ans;
    }
};

void func() {
    Solution solution;
    cout << solution.bulbSwitch(1) << endl;
    cout << solution.bulbSwitch(4) << endl;
    cout << solution.bulbSwitch(1000) << endl;
}

