#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int t = 0;
        for(int n : nums) {
            t ^= n;
        }
        return t;
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
