#include <iostream>

using namespace std;

//I = 1;
//V = 5;
//X = 10;
//L = 50;
//C = 100;
//D = 500;
//M = 1000;

class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        string symbol[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int value[]=    {1000,900,500,400, 100, 90,  50, 40,  10, 9,   5,  4,   1};
        int i, j;
        for(i=0; i<13; ++i) {
            while(num >= value[i]) {
                res += symbol[i];
                num -= value[i];
            }
        }
        return res;
    }
};

int func()
{
    Solution S;
    cout<<S.intToRoman(2345)<<endl;
    return 0;
}
