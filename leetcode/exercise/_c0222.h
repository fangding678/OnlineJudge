//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int getHeight(TreeNode* t, bool isLeft) {
        int height = 0;
        while (t) {
            ++height;
            if (isLeft) {
                t = t->left;
            } else {
                t = t->right;
            }
        }
        return height;
    }
    int countNodes(TreeNode* root) {
        int leftHeight = getHeight(root, true);
        int rightHeight = getHeight(root, false);
        if (leftHeight == rightHeight) {
            return int(pow(2, leftHeight) - 1);
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

void func() {
    Solution solution;
    TreeNode *root;
    cout << solution.countNodes(root) << endl;
}

