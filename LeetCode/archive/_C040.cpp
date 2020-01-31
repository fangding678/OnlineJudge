#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    int count_index[10000];
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
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
                if(i > index && candidates[i-1] == candidates[i]) {
                    continue;
                }
                backTrace(candidates, i+1, target, candidates[i] + sum, n+1);
            }
        }
    }
};

int func()
{
    vector<int> candidates{1, 1, 1, 10, 1, 2, 7, 6, 1, 5};
    Solution S;
    vector<vector<int>> res = S.combinationSum(candidates, 8);
    for(auto v : res) {
        for(auto i : v) {
            cout<<i<<'\t';
        }
        cout<<endl;
    }
    return 0;
}
