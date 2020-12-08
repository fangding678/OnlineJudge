#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *p = head;
        ListNode *q = NULL;
        while (head && p->val == val) {
            head = p->next;
            delete p;
            p = head;
        }
        if (!head) {
            return head;
        }
        p = head->next;
        q = head;
        while (p) {
            if (p->val == val) {
                q->next = p->next;
                delete p;
                p = q->next;
            } else {
                q = p;
                p = q->next;
            }
        }
        return head;
    }
};
