#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        ans.push_back(0);
        int len;
        int t = 1;
        while(n) {
            len = ans.size();
            while(len > 0) {
                --len;
                ans.push_back(ans[len] + t);
            }
            t *= 2;
            --n;
        }
        return ans;
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
