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
private:
    vector<TreeNode*> ans;
public:
    vector<TreeNode*> generateTrees(int n) {
        ans.clear();
        if(n < 1) {
            return ans;
        }
        ans = generateTrees(1, n);
        return ans;
    }
    vector<TreeNode*> generateTrees(int s, int e) {
        vector<TreeNode*> res;
        if(s > e) {
            TreeNode *tt = nullptr;
            res.push_back(tt);
            return res;
        }
        if(s == e) {
            TreeNode *tt = new TreeNode(s);
            res.push_back(tt);
            return res;
        }
        for(int i=s; i<=e; ++i) {
            vector<TreeNode*> res1 = generateTrees(s, i-1);
            vector<TreeNode*> res2 = generateTrees(i+1, e);
            for(auto t1 : res1) {
                for(auto t2 : res2) {
                    TreeNode *t = new TreeNode(i);
                    t->left = t1;
                    t->right = t2;
                    res.push_back(t);
                }
            }
        }
        return res;
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
