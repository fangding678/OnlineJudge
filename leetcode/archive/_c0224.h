//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include <stack>
#include "__debug"
using namespace std;

class Solution {
public:
    vector<string> convertArr(string &s) {
        int i1 = 0, i2 = 0;
        while (i2 < s.size()) {
            if (s[i2] == ' ') {
                ++i2;
            }
            s[i1++] = s[i2++];
        }
        int len = i1;
        vector<string> arr;
        int j = 0;
        bool flag = true;
        bool lastSt = true;
        for (int i = 0; i < len; ++i) {
            if (s[i] == ' ') {
                continue;
            } else if (s[i] >= '0' && s[i] <= '9') {
                if (flag) {
                    j = i;
                    flag = false;
                }
                lastSt = false;
            } else if (lastSt && s[i] == '-') {
                flag = false;
                j = i;
                lastSt = false;
            } else {
                if (!flag) {
                    arr.push_back(s.substr(j, i-j));
                }
                flag = true;
                if (s[i] == '(' || s[i] == ')' || s[i] == '+' || s[i] == '-') {
                    arr.push_back(s.substr(i, 1));
                }
                if (s[i] == '(' || s[i] == '-' || s[i] == '+') {
                    lastSt = true;
                } else {
                    lastSt = false;
                }
            }
        }
        if (!flag) {
            arr.push_back(s.substr(j, len-j));
        }
        return arr;
    }
    int calculate(string s) {
        vector<string> arr = convertArr(s);
        _print(arr);
        stack<string> opSt;
        stack<int> numSt;
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] == "(") {
                opSt.push(arr[i]);
            } else if (arr[i] == ")") {
                opSt.pop();
//                _print(opSt);
                if (!opSt.empty() && (opSt.top() == "+" || opSt.top() == "-")) {
                    int a = numSt.top();
                    numSt.pop();
                    if (numSt.empty()) {
                        a = (opSt.top() == "+") ? a : -a;
                    } else {
                        int b = numSt.top();
                        numSt.pop();
                        a = (opSt.top() == "+") ? b+a : b-a;
                    }
                    opSt.pop();
                    numSt.push(a);
                }
            } else if (arr[i] == "+" || arr[i] == "-") {
                opSt.push(arr[i]);
            } else {
                int a = stoi(arr[i]);
                if (opSt.empty() || opSt.top() == "(") {
                    numSt.push(a);
                } else {
                    int b = numSt.top();
                    numSt.pop();
                    string op = opSt.top();
                    opSt.pop();
                    a = (op == "+") ? b+a : b-a;
                    numSt.push(a);
                }
            }
        }
        _print(opSt);
        _print(numSt);
        return numSt.top();
    }
};

void func() {
    Solution solution;
    string str1 = "0"; //"1 + 1";
    string str2 = " 2-1 + 2 ";
    string str3 = "(1+(4+5+2)-3)+(6+8)";
    string str4 = "-2+1";
    string str5 = "- (3 + (4 + 5))";
    cout << solution.calculate(str1) << endl;
    cout << solution.calculate(str2) << endl;
    cout << solution.calculate(str3) << endl;
    cout << solution.calculate(str4) << endl;
    cout << solution.calculate(str5) << endl;
}

