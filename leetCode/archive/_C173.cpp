#include <iostream>
#include <string>
#include <stack>

using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
private:
    stack<TreeNode* > st;
public:
    BSTIterator(TreeNode* root) {
        BSTInit(root);
    }

    void BSTInit(TreeNode* p) {
        if (p) {
            BSTInit(p->right);
            st.push(p);
            BSTInit(p->left);
        }
    }

    /** @return the next smallest number */
    int next() {
        int res = st.top()->val;
        st.pop();
        return res;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

