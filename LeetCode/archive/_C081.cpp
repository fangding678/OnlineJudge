#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int len = nums.size();
        if(len == 0)
            return false;
        while(len > 1 && nums[len-1] == nums[0]) {
            --len;
        }
        int high = len - 1;
        int mid;
        bool flag = (target >= nums[0] ? true : false);
        while(low <= high) {
            mid = (low + high)/2;
            if(nums[mid] == target) {
                return true;
            }
            else if(nums[mid] > target) {
                if(nums[0] > nums[mid]) {
                    high = mid - 1;
                }
                else {
                    if(flag) {
                        high = mid - 1;
                    }
                    else {
                        low = mid + 1;
                    }
                }
            }
            else {
                if(nums[mid] >= nums[0]) {
                    low = mid + 1;
                }
                else {
                    if(flag) {
                        high = mid - 1;
                    }
                    else {
                        low = mid + 1;
                    }
                }
            }
        }
        return false;
    }
};

int func()
{
    Solution S;
    vector<int> v{4,5,6,7,0,1,2};
    cout<<S.search(v, 0)<<endl;
    return 0;
}
