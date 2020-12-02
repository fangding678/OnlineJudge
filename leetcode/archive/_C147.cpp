#include <iostream>
#include <unordered_map>
#include <tuple>
#include <list>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//注意：这道题目的head指针没有实际意义的值
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *q = head->next, *t1 = NULL, *t2 = NULL;
        head->next = NULL;
        while (q) {
            t1 = q;
            q = q->next;
            t2 = head;
            while (t2->next && t2->next->val <= t1->val) {
                t2 = t2->next;
            }
            t1->next = t2->next;
            t2->next = t1;
        }
        q = head->next;
        if (q && head->val > q->val) {
            t1 = head;
            head = q;
            while (q->next && q->next->val < t1->val) {
                q = q->next;
            }
            t1->next = q->next;
            q->next = t1;
        }
        return head;
    }

    //head指针有实际意义值的做法
    ListNode* insertionSortList(ListNode* head) {
        ListNode* p = head;
        if (!p || !p->next) {
            return p;
        }
        ListNode *q = head->next, *t1 = NULL, *t2 = NULL;
        while (q) {
            if (q->val < p->val) {
                t1 = q;
                q = q->next;
                t1->next = p;
                p = t1;
            } else {
                t1 = q;
                q = q->next;
                t2 = p;
                while (t2->next && t2->next->val <= t1->val) {
                    t2 = t2->next;
                }
                t1->next = t2->next;
                t2->next = t1;
            }
        }
        return p;
    }
};

