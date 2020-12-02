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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode *T = nullptr;
        int len = inorder.size();
        if(len == 0) {
            return T;
        }
        T = buildTree(inorder, 0, len-1,postorder, 0, len-1);
        return T;
    }
    TreeNode* buildTree(vector<int>& inorder, int s1, int e1, vector<int>& postorder, int s2, int e2) {
        TreeNode *t = nullptr;
        if(s1 > e1) {
            return t;
        }
        t = new TreeNode(postorder.at(e2));
        int i = e1;
        while(inorder.at(i) != postorder.at(e2)) {
            --i;
        }
        t->left = buildTree(inorder, s1, i-1, postorder, s2, s2+i-s1-1);
        t->right = buildTree(inorder, i+1, e1, postorder, s2+i-s1, e2-1);
        return t;
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
