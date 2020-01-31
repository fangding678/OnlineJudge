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
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        vector<TreeNode *> t1;
        vector<TreeNode *> t2;
        vector<vector<TreeNode *>> vec;
        vec.push_back(t1);
        vec.push_back(t2);
        if (!root) {
            return ans;
        }
        int i = 0;
        vec[i].push_back(root);
        while (!vec[i].empty()) {
            ans.push_back(vec[i][0]->val);
            for (auto t : vec[i]) {
                if (t->right) {
                    vec[1-i].push_back(t->right);
                }
                if (t->left) {
                    vec[1-i].push_back(t->left);
                }
            }
            vec[i].clear();
            i = 1 - i;
        }
        return ans;
    }
};

