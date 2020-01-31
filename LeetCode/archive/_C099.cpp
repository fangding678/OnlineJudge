#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode *p = root, *pre = nullptr;
        TreeNode *p1 = root, *p2 = root;
        bool flag = false;
        int t;
        while(p || !st.empty()) {
            if(p) {
                st.push(p);
                p = p->left;
            }
            else {
                p = st.top();
                if(pre != nullptr && !flag && pre->val > p->val) {
                    p1 = pre;
                    p2 = p;
                    flag = true;
                    t = p->val;
                }
                if(flag && t > p->val) {
                    p2 = p;
                    break;
                }
                pre = p;
                st.pop();
                p = p->right;
            }
        }
        t = p1->val;
        p1->val = p2->val;
        p2->val = t;
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
