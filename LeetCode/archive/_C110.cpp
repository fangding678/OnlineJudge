#include <iostream>
#include <map>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    bool balance;
public:
    bool isBalanced(TreeNode* root) {
        balance = true;
        int d = treeDepth(root);
        return balance;
    }
    int treeDepth(TreeNode *root) {
        if(!root || !balance) {
            return 0;
        }
        int l = treeDepth(root->left);
        int r = treeDepth(root->right);
        if(l-r > 1 || r-l > 1) {
            balance = false;
        }
        return max(l, r)+1;
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
