#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st1;
        int a1, a2;
        for (string s: tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                a2 = st1.top();
                st1.pop();
                a1 = st1.top();
                st1.pop();
                char c = s[0];
                switch (c) {
                    case '+':
                        a1 += a2;
                        break;
                    case '-':
                        a1 -= a2;
                        break;
                    case '*':
                        a1 *= a2;
                        break;
                    case '/':
                        a1 /= a2;
                        break;
                }
                st1.push(a1);
            } else {
                st1.push(atoi(s.c_str()));
            }
        }
        return st1.top();
    }
};

