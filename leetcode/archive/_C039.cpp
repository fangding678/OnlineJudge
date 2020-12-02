#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    int count_index[10000];
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int m = 0;
        int n = candidates.size();
        for(int i=1; i<n; ++i) {
            if(candidates[i] == candidates[m]) {
                continue;
            }
            candidates[++m] = candidates[i];
        }
        candidates.resize(m+1);
        res.clear();
        backTrace(candidates, 0, target, 0, 0);
        return res;
    }
    void backTrace(vector<int>& candidates, int index, int target, int sum, int n) {
        for(size_t i=index; i<candidates.size(); ++i) {
            count_index[n] = i;
            if(target == sum + candidates[i]) {
                vector<int> tres;
                for(int j=0; j<=n; ++j) {
                    tres.push_back(candidates[count_index[j]]);
                }
                res.push_back(tres);
                return ;
            }
            else if(target < candidates[i] + sum) {
                return ;
            }
            else {
                backTrace(candidates, i, target, candidates[i] + sum, n+1);
            }
        }
    }
};

int func()
{
    vector<int> candidates{2, 3, 6, 7};
    Solution S;
    vector<vector<int>> res = S.combinationSum(candidates, 7);
    for(auto v : res) {
        for(auto i : v) {
            cout<<i<<'\t';
        }
        cout<<endl;
    }
    return 0;
}
