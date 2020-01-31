#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int b, e, len = nums.size();
        int i, t;
        int diff = INT_MAX;
        if(len < 3) {
            return diff;
        }
        for(i=0; i<len-2; ++i) {
            b = i+1;
            e = len-1;
            while(b < e) {
                t = target - nums[i] - nums[b] - nums[e];
                if(abs(diff) > abs(t)) {
                    diff = t;
                }
                if(t > 0) {
                    ++b;
                }
                else if(t < 0) {
                    --e;
                }
                else
                    return target;
            }
        }
        return target - diff;
    }
};

int func()
{
    int target = 82;
    vector<int> v{1,2,4,8,16,32,64,128};
    Solution S;
    cout<<S.threeSumClosest(v, target)<<endl;
    return 0;
}
