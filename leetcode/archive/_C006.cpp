#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string res = s;
        if(numRows == 1)
            return res;
        int len = s.size();
        int i = 0, n = 0, j = 0;
        while(n < numRows){
            j = n;
            if(n==0) {
                while (j < len) {
                    res[i++] = s[j];
                    j += numRows*2 - 2;
                }
            }
            else if(n == numRows-1) {
                while(j < len) {
                    res[i++] = s[j];
                    j += numRows*2 - 2;
                }
            }
            else {
                while(j < len) {
                    res[i++] = s[j];
                    j += (numRows - n)*2 - 2;
                    if(j < len) {
                        res[i++] = s[j];
                        j += 2*n;
                    }
                }
            }
            ++n;
        }
        return res;
    }
};

int func()
{
    Solution S;
    string str = "PAYPALISHIRING";
    cout<<S.convert(str, 3)<<endl;
    return 0;
}
