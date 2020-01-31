//
// Created by fangding on 2020-01-31.
//

#ifndef ONLINEJUDGE__C210_H
#define ONLINEJUDGE__C210_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        cout << endl;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0), bfs;
        for (auto p : prerequisites) {
            if (p[0] == p[1]) {
                continue;
            }
            graph[p[1]].push_back(p[0]);
            ++indegree[p[0]];
        }
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                bfs.push_back(i);
            }
        }
        for (int i = 0; i < bfs.size(); ++i) {
            for (auto g : graph[bfs[i]]) {
                --indegree[g];
                if (0 == indegree[g]) {
                    bfs.push_back(g);
                }
            }
        }
        return bfs.size() == numCourses;
    }
};


void func() {
    Solution solution;
    int s = 15;
    vector<int> nums{2,3,1,1,1,1,1};
    cout << "res = " << solution.minSubArrayLen(s, nums) << endl;
}

#endif //ONLINEJUDGE__C210_H
