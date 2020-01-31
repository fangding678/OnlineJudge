#include <iostream>
#include <vector>
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
    bool isValidBST(TreeNode* root) {
        bool ans = true, flag = true;
        stack<TreeNode*> st;
        int temp = INT_MIN;
        while(root || !st.empty()) {
            if(root) {
                st.push(root);
                root = root->left;
            }
            else {
                root = st.top();
                st.pop();
                if(flag) {
                    temp = root->val;
                    flag = false;
                }
                else if(temp >= root->val) {
                    ans = false;
                    break;
                }
                else {
                    temp = root->val;
                }
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
