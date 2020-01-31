#include <iostream>
#include <vector>
#include <stack>

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
    void flatten(TreeNode* root) {
        TreeNode *t = root;
        TreeNode *r, *l;
        while(t) {
            if(t->left) {
                r = t->right;
                l = t->left;
                t->left = nullptr;
                t->right = l;
                while(l->right) {
                    l = l->right;
                }
                l->right = r;
            }
            t = t->right;
        }
    }
};

//¡¢º¥¥ÌÃ‚“‚
class Solution1 {
private:
    vector<TreeNode*> ans;
public:
    void flatten(TreeNode* root) {
        if(!root || (!root->left && !root->right)) {
            return ;
        }
        ans.clear();
        preOrder(root);
        TreeNode *t = root;
        for(size_t i=1; i<ans.size(); ++i) {
            t->right = ans.at(i);
            t = ans.at(i);
            t->left = nullptr;
        }
    }
    void preOrder(TreeNode *t) {
        if(t) {
            ans.push_back(t);
            preOrder(t->left);
            preOrder(t->right);
        }
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
