#include <iostream>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }
        ListNode *p = head, *q = head->next;
        while(q) {
            if(p->val == q->val) {
                while(q && p->val == q->val) {
                    p->next = q->next;
                    delete q;
                    q = p->next;
                }
            }
            else {
                p = q;
                q = p->next;
            }
        }
        return head;
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
