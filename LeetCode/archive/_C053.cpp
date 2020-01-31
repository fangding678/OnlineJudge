#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int ans;
public:
    int maxSubArray(vector<int>& nums) {
        ans = INT_MIN;
        if(nums.size() == 0) {
            return ans;
        }
        int i, len = nums.size();
        ans = nums[0];
        int t = nums[0];
        for(i=1; i<len; ++i) {
            ans = max(ans, t);
            if(t < 0) {
                t = 0;
            }
            t += nums[i];
        }
        ans = max(ans, t);
        return ans;
    }
};

int func()
{
    vector<int> v{-2,1,-3,4,-1,2,1,-5,4};
    Solution S;
    cout<<S.maxSubArray(v)<<endl;
    return 0;
}
