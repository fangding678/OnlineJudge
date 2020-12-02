#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0;
        const int d = 26;
        for (int i = 0; i < s.size(); ++i) {
            ans *= d;
            ans += int(s[i]-'A'+1);
        }
        return ans;
    }
};

