//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode *> st;
        TreeNode *t = root, *ans = root;
        while (k > 0) {
            while (t) {
                st.push(t);
                t = t->left;
            }
            ans = st.top();
            st.pop();
            --k;
            t = ans->right;
        }
        return ans->val;
    }
};

void func() {
    Solution solution;
    string str = "ads";
    cout << str << endl;
}

