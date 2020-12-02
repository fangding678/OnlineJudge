#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> ans;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        ans.clear();
        vector<int> v;
        subsets(nums, v, 0);
        return ans;
    }
    void subsets(vector<int>& nums, vector<int> &v, size_t i) {
        if(i == nums.size()) {
            ans.push_back(v);
            return ;
        }
        vector<int> v1 = v;
        v.push_back(nums[i]);
        subsets(nums, v1, i+1);
        subsets(nums, v, i+1);
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
