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
    ListNode *detectCycle(ListNode *head) {
        ListNode *p = head;
        ListNode *res = NULL;
        if (!head || !head->next) {
            return res;
        }
        ListNode *q = head;
        bool flag = false;
        while (p && q && q->next) {
            if (!q->next->next) {
                break;
            }
            p = p->next;
            q = q->next->next;
            if (p && q && p == q) {
                flag = true;
                break;
            }
        }
        if (flag) {
            p = head;
            while (p != q) {
                p = p->next;
                q = q->next;
            }
            res = p;
        }
        return res;
    }
};

