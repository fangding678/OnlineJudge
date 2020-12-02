#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<vector<int>> vec;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vec.clear();
        permute(nums, 0);
        return vec;
    }
    void permute(vector<int>& nums, size_t n) {
        for(size_t i=n; i<nums.size(); ++i) {
            size_t j = i;
            int t = nums[i];
            while(j > n) {
                nums[j] = nums[j-1];
                --j;
            }
            nums[n] = t;
            permute(nums, n+1);
            t = nums[n];
            j = n + 1;
            while(j <= i) {
                nums[j-1] = nums[j];
                ++j;
            }
            nums[i] = t;
        }
        if(n >= nums.size()) {
            vec.push_back(nums);
        }
    }
};

int func()
{
    Solution S;
    vector<int> ve{1,2,3};
    vector<vector<int>> vec = S.permute(ve);
    for(auto v : vec) {
        for(auto i : v) {
            cout<<i<<'\t';
        }
        cout<<endl;
    }
    return 0;
}
