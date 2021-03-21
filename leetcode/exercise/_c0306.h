//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
using namespace std;

class Solution {
public:
    string addTwoNum(string s1, string s2) {
        int i1 = s1.size() - 1;
        int i2 = s2.size() - 1;
        int flag = 0;
        stringstream ss;
        while (i1 >= 0 && i2 >= 0) {
            int ti = int(s1[i1] - '0') + int(s2[i2] - '0') + flag;
            if (ti > 9) {
                flag = ti / 10;
                ti = ti % 10;
            }
            ss << ti;
            --i1;
            --i2;
        }
        while (i1 >= 0) {
            int ti = int(s1[i1] - '0') + flag;
            if (ti > 9) {
                flag = ti / 10;
                ti = ti % 10;
            }
            ss << ti;
            --i1;
        }
        while (i2 >= 0) {
            int ti = int(s2[i2] - '0') + flag;
            if (ti > 9) {
                flag = ti / 10;
                ti = ti % 10;
            }
            ss << ti;
            --i2;
        }
        if (flag > 0) {
            ss << flag;
        }
        string s = ss.str();
        cout << s << endl;
        reverse(s.begin(), s.end());
        return s;
    }
    bool isAdditiveNumber(string num) {
        int len = num.size();
        for (int i = 0; i < num.size(); ++i) {
            ;
        }
        return true;
    }
};

void func() {
    Solution solution;
    cout << solution.isAdditiveNumber("112") << endl;
}

