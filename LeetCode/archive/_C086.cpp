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
    ListNode* partition(ListNode* head, int x) {
        if(!head) {
            return head;
        }
        ListNode *p = nullptr, *q = nullptr, *r = head;
        ListNode *ph = p, *qh = q;
        while(r) {
            if(r->val < x) {
                if(!ph) {
                    ph = r;
                    p = r;
                }
                else {
                    p->next = r;
                    p = r;
                }
            }
            else {
                if(!qh) {
                    qh = r;
                    q = r;
                }
                else {
                    q->next = r;
                    q = r;
                }
            }
            r = r->next;
        }
        if(q) {
            q->next = nullptr;
        }
        if(p) {
            p->next = qh;
            return ph;
        }
        return qh;
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
