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
private:
    vector<vector<int>> ans;
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        ans.clear();
        if(!root) {
            return ans;
        }
        vector<int> v;
        pathSum(root, sum, v);
        return ans;
    }
    void pathSum(TreeNode* root, int sum, vector<int> &v) {
        if(!root->left && !root->right) {
            if(root->val != sum) {
                return ;
            }
            v.push_back(sum);
            ans.push_back(v);
            return ;
        }
        sum -= root->val;
        v.push_back(root->val);
        if(root->left && root->right) {
            vector<int> v1 = v;
            pathSum(root->left, sum, v);
            pathSum(root->right, sum, v1);
        }
        else if(root->left) {
            pathSum(root->left, sum, v);
        }
        else {
            pathSum(root->right, sum, v);
        }
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
