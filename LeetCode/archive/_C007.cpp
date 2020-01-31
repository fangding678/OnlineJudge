#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        bool isPositive = x > 0 ? true : false;
        long long t = 0;
        int ans = 0;
        int p = 2147483647;
        int n = -2147483648;
        if(!isPositive)
            x = -x;
        while(x) {
            t = t*10 + x%10;
            x /= 10;
        }
        t = isPositive ? t : -1*t;
        if(t > p || t < n)
            return 0;
        ans = t;
        return ans;
    }
};

int func()
{
    Solution S;
    cout<<S.reverse(1534236469)<<endl;
    return 0;
}
