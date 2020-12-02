#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
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

