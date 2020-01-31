#include <iostream>
#include <map>

using namespace std;

//Definition for singly-linked list with a random pointer.
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        map<int, RandomListNode*> m;
        RandomListNode *phead = head;
        RandomListNode *p = NULL;
        if (!head) {
            return p;
        }
        p = new RandomListNode(head->label);
        if (m.find(p->label) == m.end()) {
            m[p->label] = p;
        }
        RandomListNode *res = p;
        phead = phead->next;
        while (phead) {
            RandomListNode *q = new RandomListNode(phead->label);
            p->next = q;
            m[q->label] = q;
            phead = phead->next;
            p = q;
        }
        phead = head;
        p = res;
        while (phead) {
            if(phead->random) {
                p->random = m[phead->random->label];
            }
            phead = phead->next;
            p = p->next;
        }
        return res;
    }
};
