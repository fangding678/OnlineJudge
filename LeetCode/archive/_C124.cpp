#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int ans;
public:
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        int t = postOrderCalc(root);
        return max(ans, t);
    }
    int postOrderCalc(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int l = postOrderCalc(root->left);
        int r = postOrderCalc(root->right);
        if(l < 0 && r < 0) {
            ans = max(ans, root->val);
            return root->val;
        }
        else if(l < 0) {
            ans = max(ans, root->val + r);
            return root->val + r;
        }
        else if(r < 0) {
            ans = max(ans, root->val + l);
            return root->val + l;
        }
        else {
            ans = max(ans, root->val + r + l);
            return root->val + max(l, r);
        }
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
