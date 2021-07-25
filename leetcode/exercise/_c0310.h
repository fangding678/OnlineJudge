//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
using namespace std;

class Solution {
public:
    int findHeight(vector<vector<int>>& nodes, vector<bool>& flag, int ind) {
        flag[ind] = true;
        int ans = 0;
        for (auto i : nodes[ind]) {
            if (flag[i]) {
                continue;
            }
            ans = max(ans, findHeight(nodes, flag, i) + 1);
        }
        return ans;
    }
    vector<int> findMinHeightTrees1(int n, vector<vector<int>>& edges) {
        vector<vector<int>> nodes;
        vector<int> ans;
        vector<bool> flag(n, false);
        unordered_map<int, int> record;
        int minHeight = n+1;
        for (int i = 0; i < n; ++i) {
            vector<int> vt;
            nodes.push_back(vt);
        }
        for (auto& edge : edges) {
            nodes[edge[0]].push_back(edge[1]);
            nodes[edge[1]].push_back(edge[0]);
        }
        for (int i = 0; i < n; ++i) {
            if (nodes[i].empty()) {
                continue;
            }

            int tmpHeight = findHeight(nodes, flag, i);
            if (minHeight >= tmpHeight) {
                minHeight = tmpHeight;
                record[i] = minHeight;
            }
            fill(flag.begin(), flag.end(), false);
        }
        _print(record);
        for (auto it = record.begin(); it != record.end(); ++it) {
            if (it->second == minHeight) {
                ans.push_back(it->first);
            }
        }
        if (ans.empty()) {
            ans.push_back(0);
        }
        return ans;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> nodes;
        for (int i = 0; i < n; ++i) {
            vector<int> vt;
            nodes.push_back(vt);
        }
        for (auto& edge : edges) {
            nodes[edge[0]].push_back(edge[1]);
            nodes[edge[1]].push_back(edge[0]);
        }
        vector<int> ans;
        unordered_map<int, int> degree;
        deque<int> deq[2];
        for (int i = 0; i < nodes.size(); ++i) {
            degree[i] = nodes[i].size();
            if (1 == nodes[i].size()) {
                deq[0].push_front(i);
            }
        }
        int f = 1;
        while (!deq[1-f].empty()) {
            int ind = deq[1-f].front();
            deq[1-f].pop_front();
            --degree[ind];
            ans.push_back(ind);
            for (auto j : nodes[ind]) {
                --degree[j];
                if (0 >= degree[j]) {
                    continue;
                } else if (1 == degree[j]) {
                    deq[f].push_front(j);
                }
            }
            if (deq[1-f].empty()) {
                if (deq[f].empty()) {
                    break;
                }
                f = 1 - f;
                ans.clear();
            }
        }
        if (ans.empty()) {
            ans.push_back(0);
        }
        return ans;
    }

};

void func() {
    Solution solution;
    vector<vector<int>> edges1;
    edges1.push_back({3,0});
    edges1.push_back({3,1});
    edges1.push_back({3,2});
    edges1.push_back({3,4});
    edges1.push_back({5,4});
    _print(solution.findMinHeightTrees(6, edges1));

    vector<vector<int>> edges2;
    edges2.push_back({1,0});
    edges2.push_back({1,2});
    edges2.push_back({1,3});
    _print(solution.findMinHeightTrees(4, edges2));

    vector<vector<int>> edges3;
    edges3.push_back({1,0});
    _print(solution.findMinHeightTrees(2, edges3));

    vector<vector<int>> edges4;
    _print(solution.findMinHeightTrees(1, edges4));


    vector<vector<int>> edges5;
    edges5.push_back({0,1});
    edges5.push_back({1,2});
    edges5.push_back({1,3});
    edges5.push_back({2,4});
    edges5.push_back({3,5});
    edges5.push_back({4,6});
    _print(solution.findMinHeightTrees(7, edges5));
    
}

