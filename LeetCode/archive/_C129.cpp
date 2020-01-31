#include <iostream>
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
private:
    int ans;
public:
    int sumNumbers(TreeNode* root) {
        ans = 0;
        sumNumbers(root, 0);
        return ans;
    }
    void sumNumbers(TreeNode* root, int t) {
        if(!root) {
            return ;
        }
        if(!root->left && !root->right) {
            ans += 10*t + root->val;
            return ;
        }
        if(!root->left) {
            sumNumbers(root->right, 10*t + root->val);
        }
        else if(!root->right) {
            sumNumbers(root->left, 10*t + root->val);
        }
        else {
            sumNumbers(root->right, 10*t + root->val);
            sumNumbers(root->left, 10*t + root->val);
        }
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
