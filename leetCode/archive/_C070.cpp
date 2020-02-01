#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n == 0) {
            return 0;
        }
        int a = 0, b = 1, i;
        for(i=0; i<n; ++i) {
            b = a+b;
            a = b-a;
        }
        return b;
    }
};

int func()
{
    Solution S;
    cout <<S.climbStairs(5)<< endl;
    return 0;
}
