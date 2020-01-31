#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root, root);
    }
    bool isSymmetric(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) {
            return true;
        }
        if(!root1 || !root2) {
            return false;
        }
        if(root1->val != root2->val) {
            return false;
        }
        return isSymmetric(root1->left, root2->right) && isSymmetric(root1->right, root2->left);
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
