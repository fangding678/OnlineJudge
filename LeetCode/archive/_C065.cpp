#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        int len = s.size();
        int i=len-1;
        while(i>=0 && s[i] == ' ') {
            --i;
        }
        len = i+1;
        s.resize(len);
        i=0;
        while(i<len && s[i] == ' ') {
            ++i;
        }
        if(i == len) {
            return false;
        }
        if(s[i] == '-' || s[i] == '+') {
            ++i;
        }
        while(i < len && isdigit(s[i])) {
            ++i;
        }
        if(i == len) {
            return true;
        }
        if(s[i] == '.') {
            if(!((i>0 && isdigit(s[i-1])) || (i<len-1 && isdigit(s[i+1])))) {
                return false;
            }
            ++i;
            while(i<len && isdigit(s[i])) {
                ++i;
            }
            if(i == len) {
                return true;
            }
        }
        if(s[i] == 'e') {
            if(!((i>0 && (isdigit(s[i-1]) || s[i-1] == '.')) &&
                 ((i<len-1 && (isdigit(s[i+1]))) || (i<len-2 && (s[i+1] == '+' || s[i+1] == '-')) ) )) {
                return false;
            }
            if(i < len-2 && (s[i+1] == '+' || s[i+1] == '-')) {
                ++i;
            }
            ++i;
            while(i<len && isdigit(s[i])) {
                ++i;
            }
            if(i == len) {
                return true;
            }
        }
        return false;
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
