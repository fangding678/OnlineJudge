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
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next) {
            return;
        }
        int len = 0;
        ListNode *p = head;
        while (p) {
            len++;
            p = p->next;
        }
        ListNode *shead = head;
        ListNode *t = head;
        for(int i=0; i<(len+1)/2; ++i) {
            if (i == (len-1)/2) {
                t = shead;
                shead = shead->next;
                t->next = NULL;
            } else {
                shead = shead->next;
            }
        }
        ListNode *q = shead->next;
        p = shead;
        p->next = NULL;
        while (q) {
            t = q->next;
            q->next = p;
            p = q;
            q = t;
        }
        shead = p;
        q = head;
        t = head;
        while (q && p) {
            q = q->next;
            t->next = p;
            t = p;
            p = p->next;
            t->next = q;
            t = q;
        }
    }
};

