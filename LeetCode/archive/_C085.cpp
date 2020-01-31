#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> v;
        int i = 0, len = heights.size();
        int ans = 0, h;
        while(i < len) {
            if(v.empty() || heights[i] > heights[v.back()]) {
                v.push_back(i);
                ++i;
            }
            else {
                h = heights[v.back()];
                v.pop_back();
                ans = max(v.empty() ? i*h : (i-v.back()-1)*h, ans);
            }
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int h = matrix.size();
        int ans = 0, i, j;
        if(h == 0) {
            return ans;
        }
        int w = matrix[0].size();
        if(w == 0) {
            return ans;
        }
        vector<vector<int>> v(h, vector<int>(w+1, 0));
        for(i=0; i<h; ++i) {
            for(j=0; j<w; ++j) {
                if(matrix[i][j] == '1') {
                    v[i][j] = (i==0) ? 1 : v[i-1][j] + 1;
                }
            }
        }
        for(i=0; i<h; ++i) {
            ans = max(largestRectangleArea(v[i]), ans);
        }
        return ans;
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
