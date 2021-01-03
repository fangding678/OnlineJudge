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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int vmax = max(p->val, q->val);
        int vmin = min(p->val, q->val);
        while (root) {
            if (root->val >= vmin && root->val <= vmax) {
                return root;
            } else if (root->val < vmax)  {
                root = root->right;
            } else {
                root = root->left;
            }
        }
        return root;
    }
};

void func() {
    Solution solution;
    string str = "ads";
    cout << str << endl;
}

