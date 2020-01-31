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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k <= 1 || head == nullptr)
            return head;
        ListNode *p = head, *q = p;
        ListNode prenode(0);
        ListNode *pre = &prenode;
        pre->next = p;
        int t;
        while(q != nullptr) {
            t = k;
            while(t > 0 && q != nullptr) {
                --t;
                q = q->next;
            }
            if(t > 0)
                break;
            p = pre->next;
            q = p->next;
            for(t=1; t<k; ++t) {
                p->next = q->next;
                q->next = pre->next;
                pre->next = q;
                q = p->next;
            }
            pre = p;
            q = pre->next;
        }
        head = prenode.next;
        return head;
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
