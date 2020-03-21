//
// Created by fangding on 2020-03-20.
//

#ifndef ONLINEJUDGE__C022_H
#define ONLINEJUDGE__C022_H

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> ans;
        TreeNode *tmp = root;
        if (!root) {
            return ans;
        }
        q.push(root);
        while (!q.empty()) {
            tmp = q.front();
            q.pop();
            ans.push_back(tmp->val);
            if (tmp->left) {
                q.push(tmp->left);
            }
            if (tmp->right) {
                q.push(tmp->right);
            }
        }
        return ans;
    }
};

void func() {
    Solution solution;
    TreeNode *t = new TreeNode(1);
    _print(solution.PrintFromTopToBottom(t));
}

#endif //ONLINEJUDGE__C022_H
