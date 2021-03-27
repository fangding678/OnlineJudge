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
            flag = ti / 10;
            ti = ti % 10;
            ss << ti;
            --i1;
            --i2;
        }
        while (i1 >= 0) {
            int ti = int(s1[i1] - '0') + flag;
            flag = ti / 10;
            ti = ti % 10;
            ss << ti;
            --i1;
        }
        while (i2 >= 0) {
            int ti = int(s2[i2] - '0') + flag;
            flag = ti / 10;
            ti = ti % 10;
            ss << ti;
            --i2;
        }
        if (flag > 0) {
            ss << flag;
        }
        string s = ss.str();
        reverse(s.begin(), s.end());
//        cout << s << endl;
        return s;
    }
    bool isAdditiveHelper(string num, int e1, int e2) {
        string num1 = num.substr(0, e1);
        string num2 = num.substr(e1, e2-e1);
        num = num.substr(e2);
        while (num.size() > 0) {
            string addNum = addTwoNum(num1, num2);
            if (e1 == 4 && e2 == 8) {
                cout << num1 << "\n" << num2 << endl;
                cout << addNum << endl;
            }
            if (addNum.size() > num.size()) {
                return false;
            }
            num1 = num2;
            num2 = num.substr(0, addNum.size());
            if (num2 != addNum) {
                return false;
            }
            num = num.substr(addNum.size());
        }
        return true;
    }
    bool isAdditiveNumber(string num) {
        int len = num.size();
        for (int i = 1; i < len - 1; ++i) {
            for (int j = i+1; j < len; ++j) {
                if (num[i] == '0') {
                    if (isAdditiveHelper(num, i, i+1)) {
                        return true;
                    }
                    break;
                }
                if (isAdditiveHelper(num, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
};

void func() {
    Solution solution;
    cout << solution.isAdditiveNumber("101") << endl;
    cout << solution.isAdditiveNumber("112358") << endl;
    cout << solution.isAdditiveNumber("199100199") << endl;
    cout << solution.isAdditiveNumber("19910011992") << endl;
    cout << endl;
    cout << solution.isAdditiveNumber("198019823962") << endl;
    cout << solution.addTwoNum("1980", "1982") << endl;
}

