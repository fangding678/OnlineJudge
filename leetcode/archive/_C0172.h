#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        const int c = 5;
        while (n) {
            ans += n/c;
            n /= 5;
        }
        return ans;
    }
};

