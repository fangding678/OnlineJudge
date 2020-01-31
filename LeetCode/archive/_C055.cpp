#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int t = 0, i;
        int len = nums.size();
        for(i=0; i<len; ++i) {
            if(t < i) {
                return false;
            }
            t = max(t, i+nums[i]);
            if(t >= len-1) {
                return true;
            }
        }
        return false;
    }
};

int func()
{
    Solution S;
    vector<int> v{3,2,1,1,4};
    cout<<S.canJump(v)<<endl;
    return 0;
}
