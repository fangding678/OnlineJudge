//
// Created by fangding on 2020-03-19.
//

#ifndef ONLINEJUDGE__C016_H
#define ONLINEJUDGE__C016_H

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode *p, *q;
        if (!pHead1) {
            return pHead2;
        } else if (!pHead2) {
            return pHead1;
        } else {
            if (pHead1->val <= pHead2->val) {
                p = pHead1;
                pHead1 = p->next;
            } else {
                p = pHead2;
                pHead2 = p->next;
            }
        }
        q = p;
        while (pHead1 && pHead2) {
            if (pHead1->val <= pHead2->val) {
                q->next = pHead1;
                q = q->next;
                pHead1 = pHead1->next;
            } else {
                q->next = pHead2;
                q = q->next;
                pHead2 = pHead2->next;
            }
        }
        while (pHead1) {
            q->next = pHead1;
            q = q->next;
            pHead1 = pHead1->next;
        }
        while (pHead2) {
            q->next = pHead2;
            q = q->next;
            pHead2 = pHead2->next;
        }
        return p;
    }
};

void func() {
    Solution solution;
    cout << solution << endl;
}

#endif //ONLINEJUDGE__C016_H
