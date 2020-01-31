#include <iostream>
#include <vector>
#include <queue>

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        ans.clear();
        queue<TreeNode*> q[2];
        if(root) {
            q[0].push(root);
        }
        TreeNode *p;
        int i = 0;
        while(!q[i].empty()) {
            vector<int> t;
            while(!q[i].empty()) {
                p = q[i].front();
                t.push_back(p->val);
                if(p->left) {
                    q[1-i].push(p->left);
                }
                if(p->right) {
                    q[1-i].push(p->right);
                }
                q[i].pop();
            }
            ans.push_back(t);
            i = 1-i;
        }
        return ans;
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
