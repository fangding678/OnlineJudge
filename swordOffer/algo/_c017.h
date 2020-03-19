//
// Created by fangding on 2020-03-19.
//

#ifndef ONLINEJUDGE__C017_H
#define ONLINEJUDGE__C017_H

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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (!pRoot1 || !pRoot2) {
            return false;
        }
        return isSubStructure(pRoot1, pRoot2) || isSubStructure(pRoot1->left, pRoot2) || isSubStructure(pRoot1->right, pRoot2);
    }
    bool isSubStructure(TreeNode *t1, TreeNode *t2) {
        if (!t2) {
            return true;
        }
        if (!t1) {
            return false;
        }
        if (t1->val == t2->val) {
            return isSubStructure(t1->left, t2->left) && isSubStructure(t1->right, t2->right);
        }
        return isSubStructure(t1->left, t2) || isSubStructure(t1->right, t2);
    }
};

void func() {
    Solution solution;
    cout << solution << endl;
}
#endif //ONLINEJUDGE__C017_H
