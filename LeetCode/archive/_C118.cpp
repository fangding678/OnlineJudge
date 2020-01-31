#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> ans;
public:
    vector<vector<int>> generate(int numRows) {
        ans.clear();
        if(numRows == 0) {
            return ans;
        }
        vector<int> v(1, 1);
        ans.push_back(v);
        int i, j;
        for(i=1; i<numRows; ++i) {
            vector<int> vt(i+1, 1);
            for(j=1; j<i; ++j) {
                vt[j] = ans[i-1][j-1] + ans[i-1][j];
            }
            ans.push_back(vt);
        }
        return ans;
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
