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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *p = head, *q = head, *r = head;
        int len = 0;
        while(p) {
            p = p->next;
            ++len;
        }
        if(len == 0) {
            return head;
        }
        k = k%len;
        p = head;
        if(k == 0) {
            return head;
        }
        while(k && q) {
            --k;
            q = q->next;
        }
        if(!q) {
            return head;
        }
        while(q->next) {
            p = p->next;
            q = q->next;
        }
        r = p->next;
        p->next = q->next;
        q->next = head;
        head = r;
        return head;
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
