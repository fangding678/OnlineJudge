#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
private:
    set<vector<int>> sv;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sv.clear();
        vector<int> v;
        sort(nums.begin(), nums.end());
        subsetsWithDup(nums, v, 0);
        vector<vector<int>> ans(sv.begin(), sv.end());
        return ans;
    }
    void subsetsWithDup(vector<int>& nums, vector<int> &v, size_t i) {
        if(i == nums.size()) {
            sv.insert(v);
            return ;
        }
        vector<int> v2 = v;
        v2.push_back(nums[i]);
        subsetsWithDup(nums, v, i+1);
        subsetsWithDup(nums, v2, i+1);
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
