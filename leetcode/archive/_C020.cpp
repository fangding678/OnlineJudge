#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        char c;
        for(size_t i=0; i<s.size(); ++i) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            }
            else if(s[i] == ')' || s[i] == '}' || s[i] == ']'){
                if(st.empty()) {
                    return false;
                }
                c = st.top();
                st.pop();
                if( (c == '(' && s[i] == ')') || (c == '[' && s[i] == ']') || (c == '{' && s[i] == '}') ) {
                    continue;
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }
        if(!st.empty()) {
            return false;
        }
        return true;
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
