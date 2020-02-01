#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        const int d = 26;
        char t;
        while (n > 0) {
            t = 'A' + char((n-1)%d);
            res = t + res;
            n = (n-1) / d;
        }
        return res;
    }
};

