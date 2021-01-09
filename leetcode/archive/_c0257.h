//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
using namespace std;

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (!root) {
            return ans;
        }
        if (!root->left && !root->right) {
            ans.push_back(to_string(root->val));
        }
        vector<string> ansLeft = binaryTreePaths(root->left);
        vector<string> ansRight = binaryTreePaths(root->right);
        for (auto &s : ansLeft) {
            ans.push_back(to_string(root->val) + "->" + s);
        }
        for (auto &s : ansRight) {
            ans.push_back(to_string(root->val) + "->" + s);
        }
        return ans;
    }
};

void func() {
    Solution solution;
    vector<int> vec{1, 2, 3, -1, 5};
    Tree tree(vec);
    _print(solution.binaryTreePaths(tree.getRoot()));
}

