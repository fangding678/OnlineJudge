#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0)
            return dividend >= 0 ? INT_MAX : INT_MIN;
        if(dividend == 0)
            return 0;
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        bool mark = false;
        int ans = 0;
        int shift = 0;
        if((divisor < 0 && dividend < 0) || (divisor > 0 && dividend >= 0))
            mark = true;
        long long d1 = dividend;
        long long d2 = divisor;
        d1 = abs(d1);
        d2 = abs(d2);
        while(d2 <= d1) {
            shift = 0;
            while(d1 >= (d2 << shift)) {
                ++shift;
            }
            d1 -= d2<<(shift - 1);
            ans += (1<<(shift - 1));
        }
        return (mark == true) ? ans : -ans;
    }
};

int func()
{
    Solution S;
    cout<<S.divide(-2147483648, -1)<<endl;
    return 0;
}
