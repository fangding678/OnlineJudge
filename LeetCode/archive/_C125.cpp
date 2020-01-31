#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int b = 0, e = n-1;
        while(b < e) {
            while(b<e && !isalnum(s[b])) {
                ++b;
            }
            while(b<e && !isalnum(s[e])) {
                --e;
            }
            if(tolower(s[b]) != tolower(s[e])) {
                return false;
            }
            ++b;
            --e;
        }
        return true;
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
