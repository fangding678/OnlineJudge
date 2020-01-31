#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

//Definition for undirected graph.
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        map<int, UndirectedGraphNode *> nodeMap;
        return cloneGraphCore(node, nodeMap);
    }
    UndirectedGraphNode *cloneGraphCore(UndirectedGraphNode *node,
                                        map<int, UndirectedGraphNode *> &nodeMap) {
        UndirectedGraphNode *ret = nullptr;
        if(node == nullptr) {
            return ret;
        }
        if(nodeMap.find(node->label) != nodeMap.end()) {
            return nodeMap[node->label];
        }
        ret = new UndirectedGraphNode(node->label);
        nodeMap[node->label] = ret;
        for(auto g : node->neighbors) {
            UndirectedGraphNode *tmp = cloneGraphCore(g, nodeMap);
            ret->neighbors.push_back(tmp);
        }
        return ret;
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
