#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode *p = head->next;
        ListNode *q = p;
        head->next = p->next;
        p->next = head;
        head = p;
        p = head->next;
        q = p->next;
        while(q != nullptr && q->next != nullptr) {
            p->next = q->next;
            q->next = q->next->next;
            p->next->next = q;
            p = q;
            q = p->next;
        }
        return head;
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
