#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        if(m == 0) {
            return ans;
        }
        int n = matrix[0].size();
        int i, j, t;
        t = (min(m, n) + 1)/2;
        for(i=0; i<t; ++i) {
            for(j=i; j<n-i; ++j) {
                ans.push_back(matrix[i][j]);
            }
            for(j=i+1; j<m-i; ++j) {
                ans.push_back(matrix[j][n-i-1]);
            }
            if(m-i-1 > i) {
                for(j=n-i-2; j>=i; --j) {
                    ans.push_back(matrix[m-i-1][j]);
                }
            }
            if(n-i-1 > i) {
                for(j=m-i-2; j>i; --j) {
                    ans.push_back(matrix[j][i]);
                }
            }
        }
        return ans;
    }
};

int func()
{
    vector<vector<int>> vec{{1,2,3}, {4,5,6}, {7,8,9}};
//    vector<int> v1{1,2,3};
//    vector<int> v2{4,5,6};
//    vector<int> v3{7,8,9};
//    vec.push_back(v1);
//    vec.push_back(v2);
//    vec.push_back(v3);
    Solution S;
    vector<int> ans = S.spiralOrder(vec);
    for(auto i : ans) {
        cout<<i<<'\t';
    }
    cout<<endl;
    return 0;
}
