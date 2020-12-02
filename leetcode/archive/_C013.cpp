#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int num = 0;
        string symbol[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int ll[] = {1,2,1,2,1,2,1,2,1,2,1,2,1};
        int value[]=    {1000,900,500,400, 100, 90,  50, 40,  10, 9,   5,  4,   1};
        int i = 0;
        for(i=0; i<13; ++i) {
            while(s.substr(0, ll[i])==symbol[i]) {
                s = s.substr(ll[i]);
                num += value[i];
            }
        }
        return num;
    }
};

int func()
{
    Solution S;
    cout<<S.romanToInt("MCMXCVI")<<endl;
    return 0;
}
