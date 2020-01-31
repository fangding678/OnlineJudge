#include <iostream>
#include <vector>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if((l1 == nullptr && l2 == nullptr) || l2 == nullptr) {
            return l1;
        }
        if(l1 == nullptr) {
            return l2;
        }
        ListNode *l = nullptr;
        if(l1->val <= l2->val) {
            l = l1;
            l1 = l1->next;
        }
        else {
            l = l2;
            l2 = l2->next;
        }
        ListNode *p = l;
        while(l1 != nullptr && l2 != nullptr) {
            if(l1->val < l2->val) {
                p->next = l1;
                p = p->next;
                l1 = l1->next;
            }
            else if(l1->val > l2->val){
                p->next = l2;
                p = p->next;
                l2 = l2->next;
            }
            else {
                p->next = l1;
                p = p->next;
                l1 = l1->next;
                p->next = l2;
                p = p->next;
                l2 = l2->next;
            }
        }
        if(l1 != nullptr) {
            p->next = l1;
        }
        if(l2 != nullptr) {
            p->next = l2;
        }
        return l;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *res = nullptr;
        size_t i;
        if(lists.size() == 0)
            return res;
        if(lists.size() == 1)
            return lists[0];
        res = mergeTwoLists(lists[0], lists[1]);
        for(i=2; i<lists.size(); ++i) {
            res = mergeTwoLists(res, lists[i]);
        }
        return res;
    }
};


//一个用例超时
class Solution1 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *res = nullptr;
        ListNode *p = res, *q = res;
        size_t t = 0, i;
        int v;
        for(i=0; i<lists.size(); ++i) {
            if(lists[i] == nullptr || (res != nullptr && res->val <= lists[i]->val)) {
                continue;
            }
            res = lists[i];
            t = i;
        }
        if(res == nullptr)
            return res;
        p = res;
        lists[t] = lists[t]->next;
        q = lists[t];
        while(1) {
            for(i=0; i < lists.size(); ++i) {
                if(lists[i] == nullptr) {
                    continue;
                }
                else {
                    v = lists[i]->val;
                    q = lists[i];
                    t = i;
                    break;
                }
            }
            if(i == lists.size())
                break;
            while(++i < lists.size()) {
                if(lists[i] == nullptr || lists[i]->val >= v) {
                    continue;
                }
                v = lists[i]->val;
                q = lists[i];
                t = i;
            }
            p->next = q;
            p = q;
            lists[t] = lists[t]->next;
        }
        return res;
    }
};

int func()
{
    cout<<endl;
    return 0;
}
