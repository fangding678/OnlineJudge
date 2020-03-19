//
// Created by fangding on 2020-03-19.
//

#ifndef ONLINEJUDGE__C018_H
#define ONLINEJUDGE__C018_H

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
    void Mirror(TreeNode *pRoot) {
        if (!pRoot || (!pRoot->left && !pRoot->right)) {
            return;
        }
        TreeNode *t = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = t;
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
};

void func() {
    Solution solution;
    cout << solution << endl;
}
#endif //ONLINEJUDGE__C018_H
