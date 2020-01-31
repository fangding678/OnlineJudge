#include <iostream>
#include <vector>
#include <stack>
#include <tuple>
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) {
            return res;
        }
        stack<TreeNode *> st;
        TreeNode *p = root;
        st.push(p);
        while (!st.empty()) {
            p = st.top();
            st.pop();
            res.push_back(p->val);
            if (p->left) {
                st.push(p->left);
            }
            if (p->right) {
                st.push(p->right);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }

    // 网友给力解决方案
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        stack<tuple<TreeNode*, bool>> s;
        s.emplace(root, false);
        while (!s.empty())
        {
            bool finished; TreeNode* crt;
            tie(crt, finished) = s.top();
            if (!finished)
            {
                get<1>(s.top()) = true;
                if (crt->right) s.emplace(crt->right, false);
                if (crt->left) s.emplace(crt->left, false);
            }
            else
            {
                result.push_back(crt->val);
                s.pop();
            }
        }
        return result;
    }
};

