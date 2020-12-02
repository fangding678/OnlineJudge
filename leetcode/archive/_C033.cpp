#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return -1;
        int b = 0;
        int e = nums.size() - 1;
        int m = 0;
        while(b < e) {
            m = b + (e-b)/2;
            if(nums[m] == target) {
                return m;
            }
            if(b == m) {
                if(nums[e] == target) {
                    return e;
                }
                return -1;
            }
            if (nums[b] < nums[m]) {
                if(target < nums[m] && target >= nums[b]) {
                    e = m-1;
                }
                else {
                    b = m+1;
                }
            }
            else {
                if(target > nums[m] && target <= nums[e]) {
                    b = m+1;
                }
                else {
                    e = m-1;
                }

            }
        }
        if(nums[b] == target) {
            return b;
        }
        return -1;
    }
};

int func()
{
    Solution S;
    vector<int> v{6,7,8,9,1,2,3,4};
    cout<<S.search(v, 4)<<endl;
    return 0;
}
