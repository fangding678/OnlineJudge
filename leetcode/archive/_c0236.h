//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
using namespace std;
#include "../_utils/_debug.h"
#include "../_utils/_struct_utils.h"


class Solution {
public:
    bool findPath(TreeNode* t, TreeNode* p, vector<TreeNode*> &path) {
        if (!t) {
            return false;
        }
        path.push_back(t);
        if (t->val == p->val) {
            return true;
        }
        if (findPath(t->left, p, path) || findPath(t->right, p, path)) {
            return true;
        }
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1;
        vector<TreeNode*> path2;
        findPath(root, p, path1);
        findPath(root, q, path2);
        int i;
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
    vector<int> vTree1{3,5,1,6,2,0,8,-1,-1,7,4};
    Tree tree = Tree(vTree1);
    TreeNode *root = tree.getRoot();
    TreeNode *p = root->left;
    TreeNode *q = root->right;
//    tree.printPostOrder();
    TreeNode *comNode = solution.lowestCommonAncestor(root, p, q);
    cout << comNode->val << endl;
}

