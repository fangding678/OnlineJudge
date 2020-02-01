#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int k = 3, i, ans = 0;
        for(i=0; i<32; ++i) {
            int mask = 1<<i, r = 0;
            for(auto num : nums) {
                r += (bool)(num&mask);
            }
            if(r%k != 0) {
                ans += mask;
            }
        }
        return ans;
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
