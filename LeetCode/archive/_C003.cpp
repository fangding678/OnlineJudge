#include <iostream>

using namespace std;

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int a[256] = {0};
        int res = 0;
        int b = 0;
        int t = 0, i, len = s.size();
        for(i = 0; i < len; ++i) {
            if(a[s[i]] == 0) {
                ++a[s[i]];
                ++t;
            }
            else {
                res = res >= (i - b) ? res : (i - b);
                ++a[s[i]];
                while(a[s[b]] == 1) {
                    --a[s[b]];
                    ++b;
                }
                --a[s[b]];
                ++b;
            }
        }
        res = res >= (i - b) ? res : (i - b);
        return res;
    }
};

