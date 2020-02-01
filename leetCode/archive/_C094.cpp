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
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode *> st;
        vector<int> ans;
        while(root!=nullptr || !st.empty()) {
            if(root) {
                st.push(root);
                root = root->left;
            }
            else {
                root = st.top();
                ans.push_back(root->val);
                st.pop();
                root = root->right;
            }
        }
        return ans;
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
