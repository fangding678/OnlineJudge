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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(n <= 0 || head == nullptr)
            return head;
        ListNode *p = head;
        ListNode *q = head;
        while(n > 0 && q != nullptr) {
            q = q->next;
            --n;
        }
        if(n > 0)
            return head;
        if(q == nullptr) {
            head = head->next;
            delete p;
            return head;
        }
        q = q->next;
        while(q != nullptr) {
            q = q->next;
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        delete q;
        return head;
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
