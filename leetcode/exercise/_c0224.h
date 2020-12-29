//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
using namespace std;

class Solution {
public:
    int calculate(string s) {
        ;
    }
};

void func() {
    Solution solution;
    string str1 = "1 + 1";
    string str2 = " 2-1 + 2 ";
    string str3 = "(1+(4+5+2)-3)+(6+8)";
    cout << solution.calculate(str1) << endl;
    cout << solution.calculate(str2) << endl;
    cout << solution.calculate(str3) << endl;
}

