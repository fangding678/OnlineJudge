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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return root;
        }
        invertTree(root->left);
        invertTree(root->right);
        TreeNode *t = root->left;
        root->left = root->right;
        root->right = t;
        return root;
    }
};

void func() {
    Solution solution;
    string str = "ads";
    cout << str << endl;
}

