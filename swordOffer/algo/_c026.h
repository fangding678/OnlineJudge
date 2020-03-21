//
// Created by fangding on 2020-03-21.
//

#ifndef ONLINEJUDGE__C026_H
#define ONLINEJUDGE__C026_H

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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        vector<TreeNode*> nList;
        InOrder(pRootOfTree, nList);
        int len = nList.size();
        if (0 == len) {
            return nullptr;
        } else if (1 == len) {
            return nList[0];
        }
        nList[0]->right = nList[1];
        for (int i = 1; i < len-1; ++i) {
            nList[i]->left = nList[i-1];
            nList[i]->right = nList[i+1];
        }
        nList[len-1]->left = nList[len-2];
        return nList[0];
    }
    void InOrder(TreeNode* root, vector<TreeNode*> &nList) {
        if (!root) {
            return;
        }
        InOrder(root->left, nList);
        nList.push_back(root);
        InOrder(root->right, nList);
    }
};

void func() {
    Solution solution;
//    cout << solution << endl;
}

#endif //ONLINEJUDGE__C026_H
