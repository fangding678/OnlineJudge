#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int b = 0, e = nums.size()-1, m;
        int x = -1, y = -1;
        if(b == e && nums[b] == target) {
            res.push_back(b);
            res.push_back(b);
            return res;
        }
        while(b <= e) {
            m = (b+e)/2;
            if(nums[m] == target) {
                x = binSerach(nums, b, m, target, true);
                y = binSerach(nums, m, e, target, false);
                break;
            }
            else if(nums[m] < target) {
                b = m+1;
            }
            else {
                e = m-1;
            }
        }
        res.push_back(x);
        res.push_back(y);
        return res;
    }
    int binSerach(vector<int> &nums, int bb, int ee, int target, bool isLeft) {
        int res = isLeft ? ee : bb;
        int b = bb, e = ee, m;
        while(b+1 < e) {
            m = (b+e)/2;
            if(target == nums[m]) {
                res = m;
                if(isLeft) {
                    e = m;
                }
                else {
                    b = m;
                }
            }
            else if(target < nums[m]) {
                e = m-1;
            }
            else {
                b = m+1;
            }
        }
        if(isLeft && nums[b] == target) {
            res = b;
        }
        if(!isLeft && nums[e] == target) {
            res = e;
        }
        return res;
    }
};

int func()
{
    Solution S;
    vector<int> v{5, 7, 7, 8, 8, 10};
    vector<int> res = S.searchRange(v, 10);
    cout<<res[0]<<'\t'<<res[1]<<endl;
    return 0;
}
