//
// Created by fangding on 2020-03-17.
//

#ifndef ONLINEJUDGE__C015_H
#define ONLINEJUDGE__C015_H

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if (!pHead || !pHead->next) {
            return pHead;
        }
        ListNode *p1 = pHead, *p2 = pHead->next, *p3 = nullptr;
        p1->next = nullptr;
        while (p2) {
            p3 = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = p3;
        }
        return p1;
    }
};

void func() {
    Solution solution;
    cout << solution << endl;
}

#endif //ONLINEJUDGE__C015_H
