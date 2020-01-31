#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        if(n == 0) {
            return ans;
        }
        if(x == 0) {
            return 0;
        }
        bool flag = false;
        if(n < 0) {
            n = -n;
            flag = true;
        }
        while(n) {
            if((n&1) == 1) {
                ans *= x;
            }
            x *= x;
            n /= 2;
        }
        if(flag) {
            ans = 1.0/ans;
        }
        return ans;
    }
};

int func()
{
    Solution S;
    cout<<S.myPow(3,4)<<endl;
    return 0;
}
