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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *p = head->next;
        head->next = NULL;
        ListNode *q = p;
        while (p) {
            q = p->next;
            p->next = head;
            head = p;
            p = q;
        }
        return head;
    }
};
