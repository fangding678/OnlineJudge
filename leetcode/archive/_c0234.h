//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode* head);

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) {
            return true;
        }
        ListNode *p1 = head, *p2 = head, *p3;
        while (p2) {
            p2 = p2->next;
            if (p2) {
                p2 = p2->next;
            }
            if (p2) {
                p1 = p1->next;
            }
        }
        if (!p1->next) {
            return true;
        }
        p2 = p1->next;
        p1->next = nullptr;
        while (p2) {
            p3 = p2->next;
            p2->next = p1->next;
            p1->next = p2;
            p2 = p3;
        }
        p3 = head;
        p2 = p1->next;
//        cout << "===" << p2->val << endl;
//        cout << "===" << p3->val << endl;
        printList(p2);
        while (p2) {
            if (p2->val != p3->val) {
                return false;
            }
            p2 = p2->next;
            p3 = p3->next;
        }
        return true;
    }
};

ListNode *conList(vector<int> &vec) {
    ListNode * head = new ListNode(vec[0]);
    ListNode *p = head, *q;
    for (int i = 1; i < vec.size(); ++i) {
        q = new ListNode(vec[i]);
        p->next = q;
        p = q;
    }
    return head;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << "\t";
        head = head->next;
    }
    cout << endl;
}

void func() {
    Solution solution;
    vector<int> v1{1, 1};
    vector<int> v2{1, 2, 1};
    vector<int> v3{1, 1, 2};
    vector<int> v4{2, 1, 1, 2};
    ListNode* head1 = conList(v1);
    ListNode* head2 = conList(v2);
    ListNode* head3 = conList(v3);
    ListNode* head4 = conList(v4);
    cout << solution.isPalindrome(head1) << endl;
    cout << solution.isPalindrome(head2) << endl;
    cout << solution.isPalindrome(head3) << endl;
    cout << solution.isPalindrome(head4) << endl;
}

