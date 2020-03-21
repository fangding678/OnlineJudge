//
// Created by fangding on 2020-03-20.
//

#ifndef ONLINEJUDGE__C025_H
#define ONLINEJUDGE__C025_H

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if (!pHead) {
            return nullptr;
        }
        vector<RandomListNode*> pList;
        RandomListNode *head, *p, *q, *t1;
        head = new RandomListNode(pHead->label);
        q = pHead;
        p = head;
        pList.push_back(p);
        while (q->next) {
            p->next = new RandomListNode(q->next->label);
            pList.push_back(p->next);
            p = p->next;
            q = q->next;
        }
        q = pHead;
        p = head;
        while (q) {
            int num = 0;
            if (q->random) {
                t1 = q->random;
                while (t1) {
                    ++num;
                    t1 = t1->next;
                }
                p->random = pList[pList.size()-num];
            }
            p = p->next;
            q = q->next;
        }
        return head;
    }
};

void func() {
    Solution solution;
    cout << solution << endl;
}

#endif //ONLINEJUDGE__C025_H
