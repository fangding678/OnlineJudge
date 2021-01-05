//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
using namespace std;

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *next_node = node->next;
        node->val = next_node->val;
        node->next = next_node->next;
        delete next_node;
    }
};

void func() {
    Solution solution;
    vector<int> vec{4,5,1,9};
    string str = "ads";
    cout << str << endl;
}

