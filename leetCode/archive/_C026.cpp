#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1)
            return nums.size();
        int t = nums[0];
        size_t i = 1;
        for(size_t j = 1; j<nums.size(); ++j) {
            if(t == nums[j]) {
                continue;
            }
            t = nums[j];
            nums[i++] = nums[j];
        }
        return i;
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
