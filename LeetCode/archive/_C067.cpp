#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string c;
        int lena = a.size();
        int lenb = b.size();
        int i = lena-1, j=lenb-1, value = 0, t, k=0;;
        while(i>=0 && j>=0) {
            t = a[i] + b[j] + value - '0' -'0';
            value = t/2;
            c += '0' + t%2;
            ++k;
            --i;
            --j;
        }
        while(i>=0) {
            t = a[i] + value - '0';
            value = t/2;
            c += '0' + t%2;
            ++k;
            --i;
        }
        while(j>=0) {
            t = b[j] + value - '0';
            value = t/2;
            c += '0' + t%2;
            ++k;
            --j;
        }
        if(value) {
            c += '0' + value;
        }
        reverse(c.begin(), c.end());
        return c;
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
