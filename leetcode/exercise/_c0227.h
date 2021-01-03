//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
using namespace std;

class Solution {
public:
    vector<string> convertArr(string s) {
        vector<string> arr;
        int len = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                continue;
            }
            s[len++] = s[i];
        }
        bool flag = false;
        int j = 0;
        for (int i = 0; i < len; ++i) {
            if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                if (flag) {
                    arr.push_back(s.substr(j, i-j));
                }
                arr.push_back(s.substr(i, 1));
                flag = false;
            } else {
                if (!flag) {
                    j = i;
                }
                flag = true;
            }
        }
        if (flag) {
            arr.push_back(s.substr(j, len-j));
        }
        return arr;
    }
    int calculate(string s) {
        vector<string> arr = convertArr(s);
        _print(arr);
        deque<int> numSt;
        deque<string> opSt;
        for (auto &a : arr) {
            if (a == "*" || a == "/" || a == "+" || a == "-") {
                opSt.push_back(a);
            } else {
                if (!opSt.empty() && (opSt.back() == "*" || opSt.back() == "/")) {
                    int x = numSt.back();
                    numSt.pop_back();
                    int y = stoi(a);
                    string op = opSt.back();
                    opSt.pop_back();
                    if (op == "*") {
                        numSt.push_back(x * y);
                    } else {
                        numSt.push_back(int(x / y));
                    }
                } else {
                    numSt.push_back(stoi(a));
                }
            }
        }
        _print(numSt);
        _print(opSt);
        while (!opSt.empty()) {
            string op = opSt.front();
            opSt.pop_front();
            int x = numSt.front();
            numSt.pop_front();
            int y = numSt.front();
            numSt.pop_front();
            if (op == "+") {
                numSt.push_front(x + y);
            } else {
                numSt.push_front(x - y);
            }
//            cout << "============ ";
//            _print(numSt);
        }
        return numSt.front();
    }
};

void func() {
    Solution solution;
    string str1 = "3+2*2";
    string str2 = " 3/2 ";
    string str3 = " 3+5 / 2 ";
    string str4 = "2+3+4";
    cout << solution.calculate(str1) << endl;
    cout << solution.calculate(str2) << endl;
    cout << solution.calculate(str3) << endl;
    cout << solution.calculate(str4) << endl;
}

