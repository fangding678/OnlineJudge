//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> findPath(TreeNode* root, Tree* p) {
        stack<TreeNode*> st;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1 = findPath(root, p);
        vector<TreeNode*> path2 = findPath(root, q);
        int i = 0;
        for (i=1; i<path1.size() && i<path2.size(); ++i) {
            if (path1[i] != path2[i]) {
                return path1[i-1];
            }
        }
        return path1[i-1];
    }
};

void func() {
    Solution solution;
    string str = "ads";
    cout << str << endl;
}

