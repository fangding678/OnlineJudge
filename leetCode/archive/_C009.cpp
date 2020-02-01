#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        int y = 0;
        int t = x;
        while(t) {
            y = y*10 + t%10;
            t /= 10;
        }
        if(x == y)
            return true;
        return false;
    }
};

int func()
{
    Solution S;
    cout<<S.isPalindrome(5345)<<endl;
    return 0;
}
