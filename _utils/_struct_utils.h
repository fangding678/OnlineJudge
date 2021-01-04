//
// Created by 方鼎 on 2021/1/4.
//
#include <vector>
#include <stack>
using namespace std;

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

class List {
public:
    List(): head(nullptr) {
    }
    List(vector<int> &vec) {
        conList(vec);
    }
    ~List() {
        ListNode *p = head;
        while (head) {
            head = head->next;
            delete p;
            p = head;
        }
    }
    void conList(vector<int> &vec) {
        head = new ListNode(vec[0]);
        ListNode *p = head, *q;
        for (int i = 1; i < vec.size(); ++i) {
            q = new ListNode(vec[i]);
            p->next = q;
            p = q;
        }
    }
    ListNode *getHead() {
        return head;
    }
    void print() {
        ListNode *p = head;
        while (p) {
            cout << p->val << "\t";
            p = p->next;
        }
        cout << endl;
    }

private:
    ListNode *head;
};

class Tree {
public:
    Tree(): root(nullptr) {
    }
    Tree(vector<int> &vec) {
        if (vec.size() < 1) {
            root = nullptr;
        }
        root = conTree(vec, 0);
    }
    ~Tree() {
        deleteTree(root);
    }
    TreeNode* conTree(vector<int> &vec, int ind) {
        TreeNode *t = nullptr;
        if (vec.size() > ind && vec[ind] >= 0) {
            t = new TreeNode(vec[ind]);
            t->left = conTree(vec, 2*ind+1);
            t->right = conTree(vec, 2*ind+2);
        }
        return t;
    }
    void deleteTree(TreeNode *t) {
        if (!t) {
            return;
        }
        deleteTree(t->left);
        deleteTree(t->right);
        delete t;
    }
    void printPreOrder() {
        cout << "begin PreOrder..." << endl;
        stack<TreeNode *> st;
        TreeNode *t = root;
        while (!st.empty() || t) {
            while (t) {
                cout << t->val << "\t";
                st.push(t);
                t = t->left;
            }
            if (!st.empty()) {
                t = st.top();
                st.pop();
                t = t->right;
            }
        }
        cout << endl;
        cout << "end PreOrder..." << endl;
    }
    void printInOrder() {
        cout << "begin InOrder..." << endl;
        stack<TreeNode *> st;
        TreeNode *t = root;
        while (!st.empty() || t) {
            while (t) {
                st.push(t);
                t = t->left;
            }
            if (!st.empty()) {
                t = st.top();
                st.pop();
                cout << t->val << "\t";
                t = t->right;
            }
        }
        cout << endl;
        cout << "end InOrder..." << endl;
    }
    void printPostOrder() {
        cout << "begin PostOrder..." << endl;
        stack<TreeNode *> st;
        TreeNode *pre = nullptr;
        TreeNode *cur;
        st.push(root);
        while (!st.empty()) {
            cur = st.top();
            if ((!cur->left && !cur->right) || (pre && (pre==cur->left || pre==cur->right))) {
                cout << cur->val << "\t";
                pre = cur;
                st.pop();
            } else {
                if (cur->right) {
                    st.push(cur->right);
                }
                if (cur->left) {
                    st.push(cur->left);
                }
            }
        }
        cout << endl;
        cout << "end PostOrder..." << endl;
    }
    TreeNode *getRoot() {
        return root;
    }

private:
    TreeNode *root;
};



#endif //ONLINEJUDGE__STRUCT_UTILS_H
