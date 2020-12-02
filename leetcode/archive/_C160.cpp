#include <iostream>
#include <vector>

using namespace std;

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        ListNode *p = headA, *q;
        while (p) {
            lenA++;
            p = p->next;
        }
        p = headB;
        while (p) {
            lenB++;
            p = p->next;
        }
        p = headA;
        q = headB;
        if (lenA > lenB) {
            for (int i = 0; i < lenA - lenB; ++i) {
                p = p->next;
            }
        } else if (lenB > lenA) {
            for (int i = 0; i < lenB - lenA; ++i) {
                q = q->next;
            }
        }
        while (p && q) {
            if (p == q) {
                break;
            }
            p = p->next;
            q = q->next;
        }
        return p;
    }
};

