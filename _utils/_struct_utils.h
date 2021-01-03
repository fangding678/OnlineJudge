//
// Created by 方鼎 on 2021/1/4.
//

#ifndef ONLINEJUDGE__STRUCT_UTILS_H
#define ONLINEJUDGE__STRUCT_UTILS_H

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};



#endif //ONLINEJUDGE__STRUCT_UTILS_H
