#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int i=0, j=0;
        int res = 0;
        int t = res;
        int m = 0, n = 0;
        bool *mark = new bool[len];
        memset(mark, false, sizeof(bool)*len);
        for(i=len-1; i>0; --i) {
            if(n < height[i]) {
                n = height[i];
            }
            else {
                mark[i] = true;
            }
        }
        for(i=0; i<len-1; ++i) {
            if(height[i] <= m)
                continue;
            m = height[i];
            for(j=len-1; j>i; --j) {
                if(mark[j])
                    continue;
                t = (j-i)*min(height[i], height[j]);
                if(res < t) {
                    res = t;
                }
            }
        }
        delete[] mark;
        return res;
    }
};

int func()
{
    int a[] = {1,1,1};
    vector<int> v(begin(a), end(a));
    Solution S;
    cout<<S.maxArea(v)<<endl;
    return 0;
}
