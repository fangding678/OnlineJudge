#include <iostream>

using namespace std;

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        map<int, int> m;
        for(auto i = 0; i < nums.size(); ++i) {
            map<int, int>::iterator ii;
            if((ii = m.find(target - nums[i])) != m.end())
            {
                res.push_back(ii->second);
                res.push_back(i);
                break;
            }
            m[nums[i]] = i;
        }
        return res;
    }
};

