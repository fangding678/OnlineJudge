#include <iostream>
#include <unordered_map>
#include <tuple>
#include <list>
#include <algorithm>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *p1 = NULL, *p2 = NULL, *q, *t1;
        q = head->next;
        while (q) {
            if (q->val < head->val) {
                if (!p1) {
                    t1 = q->next;
                    p1 = q;
                    p1->next = NULL;
                    q = t1;
                } else {
                    t1 = q->next;
                    q->next = p1->next;
                    p1->next = q;
                    q = t1;
                }
            } else {
                if (!p2) {
                    t1 = q->next;
                    p2 = q;
                    p2->next = NULL;
                    q = t1;
                } else {
                    t1 = q->next;
                    q->next = p2->next;
                    p2->next = q;
                    q = t1;
                }
            }
        }
        p1 = sortList(p1);
        p2 = sortList(p2);
        if (!p1) {
            head->next = p2;
            return head;
        }
        t1 = p1;
        while (t1->next) {
            t1 = t1->next;
        }
        t1->next = head;
        head->next = p2;
        return p1;
    }
};

