//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        nums.push_back(-1);
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] != i && nums[i] >= 0) {
                int j = nums[i];
                int tmp = nums[j];
                nums[j] = nums[i];
                nums[i] = tmp;
            }
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < 0) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};

void func() {
    Solution solution;
    vector<int> v1{3,0,1};
    vector<int> v2{9,6,4,2,3,5,7,0,1};
    vector<int> v3{0};
    cout << solution.missingNumber(v1) << endl;
    cout << solution.missingNumber(v2) << endl;
    cout << solution.missingNumber(v3) << endl;
}

