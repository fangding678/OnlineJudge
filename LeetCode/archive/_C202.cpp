#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        int t, i;
        while (s.find(n) == s.end()) {
            s.insert(n);
            t = 0;
            while (n) {
                i = n%10;
                t += i*i;
                n /= 10;
            }
            n = t;
        }
        if (n == 1) {
            return true;
        }
        return false;
    }
};

