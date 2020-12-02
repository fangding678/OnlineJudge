#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int value = 1, t;
        int i, len = digits.size();
        vector<int> ans(len, 0);
        for(i=len-1; i>=0; --i) {
            t = digits[i] + value;
            value = t/10;
            ans[i] = t%10;
        }
        if(value) {
            ans.insert(ans.begin(), 1);
        }
        return ans;
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
