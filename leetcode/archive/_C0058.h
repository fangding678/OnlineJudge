#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.size(), i;
        int ans = 0;
        for(i=len-1; i>=0; --i) {
            if(s[i] != ' ') {
                break;
            }
        }
        for(; i>=0; --i) {
            if(s[i] == ' ') {
                break;
            }
            ++ans;
        }
        return ans;
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
