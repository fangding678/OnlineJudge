//
// Created by fangding on 2020-03-10.
//

#ifndef ONLINEJUDGE__C001_H
#define ONLINEJUDGE__C001_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int len = pre.size();
        return reConstructBinaryTree(pre, 0, vin, 0, len);
    }

    TreeNode* reConstructBinaryTree(vector<int> &pre, int pstart, vector<int> &vin, int vstart, int len) {
        if (0 == len) {
            return nullptr;
        }
        TreeNode* t = new TreeNode(pre[pstart]);
        if (1 == len) {
            return t;
        }
        int gen = 0;
        for (int i = 0; i < len; ++i) {
            if (vin[vstart+i] == pre[pstart]) {
                gen = i;
                break;
            }
        }
        t->left = reConstructBinaryTree(pre, pstart+1, vin, vstart, gen);
        t->right = reConstructBinaryTree(pre, pstart+gen+1, vin, vstart+gen+1, len-gen-1);
        return t;
    }
};

void func() {
    Solution solution;
    vector<int> pre{1,2,4,7,3,5,6,8};
    vector<int> vin{4,7,2,1,5,3,8,6};
    solution.reConstructBinaryTree(pre, vin);
}

#endif //ONLINEJUDGE__C001_H
