#include <iostream>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        long long t = 0;
        int ans = 0, i = 0;
        int len = str.size();
        int p = 2147483647;     //(1<<31)-1;
        int n = -2147483648;    //(1<<31);
        while(i <len && (str[i] == ' ' || str[i] == '0'))
            ++i;
        bool isPositive = (str[i] == '-') ? false : true;
        if(str[i] == '-' || str[i] == '+')
            ++i;
        if(isPositive) {
            while(i < len) {
                if(str[i] < '0' || str[i] > '9')
                    break;
                t = t*10 + str[i++] - '0';
                if(t >= p)
                    return p;
            }
        }
        else {
            while(i < len) {
                if(str[i] < '0' || str[i] > '9')
                    break;
                t = t*10 + str[i++] - '0';
                if(-1*t < n)
                    return n;
            }
        }
        t = isPositive ? t : -1*t;
        ans = t;
        return ans;
    }
};

int func()
{
    Solution S;
    cout<<S.myAtoi("  -0012a42")<<endl;
    return 0;
}
