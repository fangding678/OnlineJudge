#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0)
            return 0;
        size_t b = 0;
        size_t e = 0;

        while(e < nums.size()) {
            swap(nums[b], nums[e]);
            while(b < nums.size() && nums[b] != val) {
                ++b;
            }
            e = b+1;
            while(e < nums.size() && nums[e] == val) {
                ++e;
            }
        }
        return b;
    }
};

int func()
{
    Solution S;
    vector<int> v{3,3};
    int val = 3;
    val = S.removeElement(v, val);
    for(int i=0; i<val; ++i) {
        cout<<v[i]<<'\t';
    }
    cout<<endl;
    return 0;
}
