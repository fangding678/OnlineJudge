#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> bmax, lmax;
        int ans = 0, t;
        int i, len = height.size();
        if(len <= 2)
            return ans;
        t = height[0];
        bmax.push_back(t);
        for(i=1; i<len; ++i) {
            if(height[i] >= t) {
                t = height[i];
            }
            bmax.push_back(t);
        }
        t = height[len-1];
        lmax.push_back(t);
        for(i=len-2; i>=0; --i) {
            if(height[i] >= t) {
                t = height[i];
            }
            lmax.push_back(t);
        }
        reverse(lmax.begin(), lmax.end());
        for(i=1; i<len-1; ++i) {
            ans += min(bmax[i], lmax[i]) - height[i];
        }
        return ans;
    }
};

int func()
{
    Solution S;
    vector<int> vt{0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<S.trap(vt)<<endl;
    return 0;
}
