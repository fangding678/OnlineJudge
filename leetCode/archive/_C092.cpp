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
    ListNode* reverseBetween(ListNode* head, ListNode *last) {
        ListNode *p = head;
        while(p != last) {
            head = p->next;
            p->next = last->next;
            last->next = p;
            p = head;
        }
        return head;
    }
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *pre = head, *p = pre->next, *q = head, *r = nullptr;
        if(m == n) {
            return head;
        }
        while(m > 2) {
            q = q->next;
            --m;
            --n;
        }
        pre = q;
        p = pre->next;
        while(n > 1) {
            q = q->next;
            --n;
        }
        if(m == 1) {
            return reverseBetween(head, q);
        }
        r = reverseBetween(p, q);
        pre->next = r;
//        r = p->next;
//        p->next = q->next;
//        while(r != q->next) {
//            p = r->next;
//            r->next = pre->next;
//            pre->next = r;
//            r = p;
//        }
        return head;
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
