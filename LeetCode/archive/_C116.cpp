#include <iostream>
#include <queue>

using namespace std;

//Definition for binary tree with next pointer.
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) {
            return;
        }
        queue<TreeLinkNode*> q[2];
        TreeLinkNode *p = root, *t, *tp;
        int i=0;
        q[i].push(p);
        while(!q[0].empty() || !q[1].empty()) {
            tp = nullptr;
            while(!q[i].empty()) {
                t= q[i].front();
                q[i].pop();
                t->next = tp;
                tp = t;
                if(t->right) {
                    q[1-i].push(t->right);
                }
                if(t->left) {
                    q[1-i].push(t->left);
                }
            }
            i = 1-i;
        }
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
