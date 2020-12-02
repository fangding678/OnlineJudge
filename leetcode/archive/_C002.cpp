#include <iostream>

using namespace std;

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l = nullptr;
        ListNode *q;
        int jinwei = 0;
        while(l1 != nullptr && l2 != nullptr) {
            ListNode *p = new ListNode((jinwei + l1->val + l2->val)%10);
            if(l == nullptr)
            {
                l = p;
                q = p;
            }
            else {
                q->next = p;
                q = p;
            }
            if(jinwei + l1->val + l2->val >= 10)
                jinwei = 1;
            else
                jinwei = 0;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != nullptr) {
            ListNode *p = new ListNode((jinwei + l1->val)%10);
            if(l == nullptr)
            {
                l = p;
                q = p;
            }
            else {
                q->next = p;
                q = p;
            }
            if(jinwei + l1->val >= 10)
                jinwei = 1;
            else
                jinwei = 0;
            l1 = l1->next;
        }
        while(l2 != nullptr) {
            ListNode *p = new ListNode((jinwei + l2->val)%10);
            if(l == nullptr)
            {
                l = p;
                q = p;
            }
            else {
                q->next = p;
                q = p;
            }
            if(jinwei + l2->val >= 10)
                jinwei = 1;
            else
                jinwei = 0;
            l2 = l2->next;
        }
        if(jinwei > 0)
        {
            ListNode *p = new ListNode(jinwei);
            q->next = p;
            q = p;
        }
        return l;
    }
};

