#include <iostream>
#include <vector>

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0) {
            return nullptr;
        }
        int len = preorder.size();
        TreeNode *T = buildTree(preorder, 0, len-1, inorder, 0, len-1);
        return T;
    }
    TreeNode* buildTree(vector<int>& preorder, int s1, int e1, vector<int>& inorder, int s2, int e2) {
        TreeNode *t = nullptr;
        if(s1 > e1) {
            return t;
        }
        t = new TreeNode(preorder.at(s1));
        if(s1 == e1) {
            return t;
        }
        int i = s2;
        while(inorder.at(i) != preorder.at(s1)) {
            ++i;
        }
        t->left = buildTree(preorder, s1+1, s1+i-s2, inorder, s2, i-1);
        t->right = buildTree(preorder, s1+i-s2+1, e1, inorder, i+1, e2);
        return t;
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
