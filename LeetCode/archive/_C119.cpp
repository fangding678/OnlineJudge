#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> vec;
        vector<int> v1(rowIndex+1, 1);
        vector<int> v2(rowIndex+1, 1);
        vec.push_back(v1);
        vec.push_back(v2);
        int i = 1, j, k;
        for(k=1; k<rowIndex; ++k) {
            for(j=1; j<=k; ++j) {
                vec[i][j] = vec[1-i][j-1] + vec[1-i][j];
            }
            i = 1-i;
        }
        return vec[1-i];
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
