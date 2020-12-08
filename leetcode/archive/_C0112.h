#include <iostream>

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
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) {
            return false;
        }
        return hasPathSum(root, sum, root->val);
    }
    bool hasPathSum(TreeNode* root, int sum, int ans) {
        if(!root->left && !root->right) {
            return ans == sum;
        }
        if(!root->left) {
            return hasPathSum(root->right, sum, ans+root->right->val);
        }
        if(!root->right) {
            return hasPathSum(root->left, sum, ans+root->left->val);
        }
        return hasPathSum(root->left, sum, ans+root->left->val)
        || hasPathSum(root->right, sum, ans+root->right->val);
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
