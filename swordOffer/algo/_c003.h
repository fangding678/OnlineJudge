//
// Created by fangding on 2020-03-10.
//

#ifndef ONLINEJUDGE__C001_H
#define ONLINEJUDGE__C001_H

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> ans;
        if (head) {
            tt(ans, head);
        }
        return ans;
    }

    void tt(vector<int> &ans, ListNode* head) {
        if (head->next) {
            tt(ans, head->next);
        }
        ans.push_back(head->val);
    }
};

void func() {
    Solution solution;
}

#endif //ONLINEJUDGE__C001_H
