#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        ans.clear();
        queue<TreeNode*> q[2];
        if(!root) {
            return ans;
        }
        int i=0;
        q[i].push(root);
        TreeNode *t;
        while(!q[0].empty() || !q[1].empty()) {
            vector<int> v;
            while(!q[i].empty()) {
                t = q[i].front();
                v.push_back(t->val);
                q[i].pop();
                if(t->left) {
                    q[1-i].push(t->left);
                }
                if(t->right) {
                    q[1-i].push(t->right);
                }
            }
            i = 1-i;
            ans.push_back(v);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
