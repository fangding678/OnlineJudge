#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        vector<vector<int>> res;
        size_t len = nums.size();
        size_t i, j, b, e;
        int t;
        vector<int> v{target, target, -target, 1-target};
        if(len < 4)
        {
            return res;
        }
        sort(nums.begin(), nums.end());
        for(i=0; i<len-3; ++i)
        {
            while(i < len-3 && i>0 && nums[i] == nums[i-1]) {
                ++i;
            }
            for(j=i+1; j<len-2; ++j)
            {
                while(j < len-2 && j>i+1 && nums[j] == nums[j-1]) {
                    ++j;
                }
                b = j+1;
                e=len-1;
                while(b < e)
                {
                    t = nums[i] + nums[j] +nums[b] + nums[e];
                    if(target == t)
                    {
                        vector<int> vt{nums[i], nums[j], nums[b], nums[e]};
                        if(v != vt) {
                            res.push_back(vt);
                            v = vt;
                        }
                        ++b;
                        while(b < e && nums[b] == nums[b-1]) {
                            ++b;
                        }
                        --e;
                        while(b < e && nums[e] == nums[e+1]) {
                            --e;
                        }
                    }
                    else if(target > t)
                    {
                        ++b;
                    }
                    else
                    {
                        --e;
                    }
                }
            }
        }
        return res;
    }
};

int func()
{
    Solution S;
    vector<int> nums{1,0,-1,0,-2,2};
    int target = 0;
    vector<vector<int>> res = S.fourSum(nums, target);
    for(size_t i=0; i<res.size(); ++i)
    {
        for(size_t j=0; j<res[i].size(); ++j)
        {
            cout<<res[i][j]<<'\t';
        }
        cout<<endl;
    }
    return 0;
}
