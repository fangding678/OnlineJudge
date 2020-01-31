#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(nums.size() <= 2) {
            return nums.size();
        }
        int i=0, j=2, k=0;
        while(j<len) {
            if(nums[i] != nums[j]) {
                nums[k++] = nums[i];
            }
            ++i;
            ++j;
        }
        while(i < len) {
            nums[k++] = nums[i++];
        }
        return k;
    }
};

int func()
{
    Solution S;
    vector<int> v{1,1,1,2,2,3};
    cout <<S.removeDuplicates(v)<< endl;
    return 0;
}
