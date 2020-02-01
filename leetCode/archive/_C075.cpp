#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        int low = 0, high = len-1;
        while(low < high) {
            while(low < high && nums[low] == 0) ++low;
            while(low < high && nums[high] != 0) --high;
            swap(nums[low], nums[high]);
        }
        high = len-1;
        while(low < high) {
            while(low < high && nums[low] == 1) ++low;
            while(low < high && nums[high] != 1) --high;
            swap(nums[low], nums[high]);
        }
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
