#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
private:
    set<vector<int>> sv;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sv.clear();
        permuteUnique(nums, 0);
        vector<vector<int>> vec(sv.begin(), sv.end());
        return vec;
    }
    void permuteUnique(vector<int>& nums, size_t n) {
        for(size_t i=n; i<nums.size(); ++i) {
            if(i != n && nums[i] == nums[n]) {
                continue;
            }
            swap(nums[i], nums[n]);
            permuteUnique(nums, n+1);
            swap(nums[i], nums[n]);
        }
        if(n >= nums.size()) {
            sv.insert(nums);
        }
    }
};

//Time Limits Exceed
class Solution1 {
private:
    set<vector<int>> sv;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sv.clear();
        permuteUnique(nums, 0);
        vector<vector<int>> vec(sv.begin(), sv.end());
        return vec;
    }
    void permuteUnique(vector<int>& nums, size_t n) {
        for(size_t i=n; i<nums.size(); ++i) {
            size_t j = i;
            int t = nums[i];
            while(j > n) {
                nums[j] = nums[j-1];
                --j;
            }
            nums[n] = t;
            permuteUnique(nums, n+1);
            t = nums[n];
            j = n + 1;
            while(j <= i) {
                nums[j-1] = nums[j];
                ++j;
            }
            nums[i] = t;
        }
        if(n >= nums.size()) {
            sv.insert(nums);
        }
    }
};

int func()
{
    Solution S;
    vector<int> ve{3,3,0,0,2,3,2};
    vector<vector<int>> vec = S.permuteUnique(ve);
    for(auto v : vec) {
        for(auto i : v) {
            cout<<i<<'\t';
        }
        cout<<endl;
    }
    return 0;
}
