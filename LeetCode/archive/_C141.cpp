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
    bool hasCycle(ListNode *head) {
        ListNode *p = head;
        if (!head || !head->next) {
            return false;
        }
        ListNode *q = head->next;
        bool res = false;
        while (p && q) {
            if (!q->next) {
                break;
            }
            if (p->next && q->next->next && p->next == q->next->next) {
                res = true;
                break;
            }
            p = p->next;
            q = q->next->next;
        }
        return res;
    }
};

