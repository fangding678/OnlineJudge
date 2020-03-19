//
// Created by fangding on 2020-03-17.
//

#ifndef ONLINEJUDGE__C014_H
#define ONLINEJUDGE__C014_H

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode *p1 = pListHead, *p2 = pListHead;
        while (p1 && k>0) {
            p1 = p1->next;
            --k;
        }
        if (k > 0) {
            return nullptr;
        }
        while (p1) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p2;
    }
};

void func() {
    Solution solution;
    cout << solution << endl;
}

#endif //ONLINEJUDGE__C014_H
