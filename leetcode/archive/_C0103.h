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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        ans.clear();
        stack<TreeNode*> q[2];
        if(root) {
            q[0].push(root);
        }
        TreeNode *p;
        int i = 0;
        while(!q[i].empty()) {
            vector<int> t;
            while(!q[i].empty()) {
                p = q[i].top();
                t.push_back(p->val);
                if(i == 0) {
                    if(p->left) {
                        q[1-i].push(p->left);
                    }
                    if(p->right) {
                        q[1-i].push(p->right);
                    }
                }
                else {
                    if(p->right) {
                        q[1-i].push(p->right);
                    }
                    if(p->left) {
                        q[1-i].push(p->left);
                    }
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
