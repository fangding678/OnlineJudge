#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) {
            return 0;
        }
        double res = 1, last = 0;
        while(res != last) {
            last = res;
            res = (res + x/res)/2;
        }
        return int(res);
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
