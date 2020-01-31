#include <iostream>
#include <vector>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode *p = head;
        int n = 0;
        while(p) {
            p = p->next;
            ++n;
        }
        TreeNode *T = sortedListToBST(head, n);
        return T;
    }
    TreeNode* sortedListToBST(ListNode* head, int n) {
        TreeNode *t = nullptr;
        if(n == 0) {
            return t;
        }
        if(n == 1) {
            t = new TreeNode(head->val);
            return t;
        }
        int m = n/2;
        ListNode * p = head;
        while(m) {
            --m;
            p = p->next;
        }
        t = new TreeNode(p->val);
        t->left = sortedListToBST(head, n/2);
        t->right = sortedListToBST(p->next, n-n/2-1);
        return t;
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
