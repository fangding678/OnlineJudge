#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int t = 0, i;
        int len = nums.size();
        for(i=0; i<len; ++i) {
            t = nums[i];
            if(t == i+1 || t <= 0 || t > len) {
                continue;
            }
            while(t > 0 && t <= len && nums[t-1] != t) {
                swap(nums[i], nums[t-1]);
                t = nums[i];
            }
        }
        for(i=0; i<len; ++i) {
            if(nums[i] != i+1)
                return i+1;
        }
        return i+1;
    }
};

int func()
{
    vector<int> v{3,4,-1,1};
    Solution S;
    cout << S.firstMissingPositive(v) << endl;
    return 0;
}
