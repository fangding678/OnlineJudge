#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.empty()) {
            return 0;
        }
        heights.insert(heights.begin(), -1);
        heights.push_back(-1);
        stack<int> st;
        int len = heights.size();
        int i, h, ans = 0;
        for(i=0; i<len; ++i) {
            while(!st.empty() && heights[i] <= heights[st.top()]) {
                h = heights[st.top()];
                st.pop();
                if(heights[i] < h) {
                    ans = max(ans, (i-st.top()-1)*h);
                }
            }
            st.push(i);
        }
        heights.pop_back();
        heights.erase(heights.begin());
        return ans;
    }
};

//Time Limit Exceeded
class Solution1 {
public:
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        if(len == 0) {
            return 0;
        }
        return largestRectangleArea(heights, 0, len-1);
    }
    inline int max(int a, int b, int c) {
        if(a > b) {
            return a > c ? a : c;
        }
        else {
            return b > c ? b : c;
        }
    }
    int largestRectangleArea(vector<int> & heights, int b, int e) {
        if(b > e) {
            return 0;
        }
        int m = b;
        int i;
        for(i=b+1; i<=e; ++i) {
            if(heights[i] < heights[m]) {
                m = i;
            }
        }
        return max(largestRectangleArea(heights, b, m-1),
                   largestRectangleArea(heights, m+1, e), (e-b+1)*heights[m]);
    }
};

int func()
{
    Solution S;
    vector<int> v{2,3,4,5};
    cout<<S.largestRectangleArea(v)<<endl;
    return 0;
}
