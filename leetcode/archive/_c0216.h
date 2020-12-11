//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    void bfs(vector<int> &vec, int k, int n, int num) {
        if (k == 0 && n == 0) {
            ans.push_back(vec);
            return ;
        }
        if (n < num || num > 9) {
            return;
        }
        vec.push_back(num);
        bfs(vec, k-1, n-num, num+1);
        vec.pop_back();
        bfs(vec, k, n, num+1);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        ans.clear();
        vector<int> vec;
        bfs(vec, k, n, 1);
        return ans;
    }
};

void func() {
    Solution solution;
    auto ans = solution.combinationSum3(5, 20);
    for (auto v : ans) {
        _print(v);
    }
}

