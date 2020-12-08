#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//²Î¿¼STL
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 1)
            return;
        size_t i = nums.size() - 1;
        size_t ii, j;
        while(1) {
            ii = i;
            --i;
            if(nums[i] < nums[ii]) {
                j = nums.size();
                while(nums[i] >= nums[--j]) {;}
                swap(nums[i], nums[j]);
                reverse(nums.begin()+ii, nums.end());
                return;
            }
            if(i == 0) {
                reverse(nums.begin(), nums.end());
                return;
            }
        }
    }
};

int func()
{
    vector<int> v{1,3,2};
    Solution S;
    S.nextPermutation(v);
    for(auto i : v) {
        cout<<i<<'\t';
    }
    cout<<endl;
    return 0;
}
