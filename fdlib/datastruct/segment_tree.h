//
// Created by 方鼎 on 2021/12/5.
//

#ifndef ONLINEJUDGE_SEGMENT_TREE_H
#define ONLINEJUDGE_SEGMENT_TREE_H


#include <string>
#include <vector>

using namespace std;

enum SegType {
    Sum,
    Max,
    Min
};

class SegmentTree {
private:
    int num = 0;
    SegNode *root;
    SegType stype = SegType::Sum;
public:
    SegmentTree(int* arr, int len, SegType stype=SegType::Sum) {
        this->stype = stype;
        this->num = len;
        this->root = build(arr, 0, len-1);
    }

    SegNode* getRoot() {
        return this->root;
    }

    int getNum() {
        return this->num;
    }

    int getMid(SegNode * segNode) {
        return (segNode->start + segNode->end) / 2;
    }

    SegNode* build(int *arr, int s, int e) {
        if (s > e) {
            return nullptr;
        }
        SegNode *node = new SegNode(s, e);
        if (s == e) {
            node->value = arr[s];
            return node;
        }
        int mid = (s + e) / 2;
        node->left = build(arr, s, mid);
        node->right = build(arr, mid+1, e);
        if (this->stype == SegType::Min) {
            node->value = min(node->left->value, node->right->value);
        } else if (this->stype == SegType::Max) {
            node->value = max(node->left->value, node->right->value);
        } else {
            node->value = node->left->value + node->right->value;
        }
        return node;
    }

    int query(SegNode *node, int s, int e) {
        if (s > e) {
            cout << "error param" << endl;
            return -1;
        }
        if (node->start == s && node->end == e) {
            return node->value;
        }
        int mid = getMid(node);
        if (mid >= e) {
            return query(node->left, s, e);
        }
        if (mid < s) {
            return query(node->right, s, e);
        }
        if (this->stype == SegType::Max) {
            return max(query(node->left, s, mid), query(node->right, mid+1, e));
        } else if (this->stype == SegType::Min) {
            return min(query(node->left, s, mid), query(node->right, mid+1, e));
        } else {
            return query(node->left, s, mid) + query(node->right, mid+1, e);
        }
    }

    void update(SegNode *node, int index, int value) {
        if (index > node->end || index < node->start) {
            return ;
        }
        if (node->start == index && node->end == index) {
            node->value = value;
            return ;
        }
        int mid = getMid(node);
        if (mid > index) {
            update(node->right, index, value);
        } else {
            update(node->left, index, value);
        }
        if (this->stype == SegType::Max) {
            node->value = max(node->left->value, node->right->value);
        } else if (this->stype == SegType::Min) {
            node->value = min(node->left->value, node->right->value);
        } else {
            node->value = node->left->value + node->right->value;
        }
    }

};

class BinaryIndexTree {
private:
    int *bitArr;
    int num;
    const SegType stype = SegType::Sum;
public:
    BinaryIndexTree(int *arr, int len) {
        this->num = len;
        this->bitArr = new int[num + 1];
        for (int i = len-1; i >= 0; --i) {
            this->bitArr[i+1] = 0;
            update(i+1, arr[i]);
        }
        _print(bitArr, len+1);
    }

    int lowbit(int x) {
        return x & (-x);
    }

    void update(int i, int k) {
        while (i <= this->num) {
            this->bitArr[i] += k;
            i += lowbit(i);
        }
    }

    int getSum(int i) {
        int ans = 0;
        while (i > 0) {
            ans += this->bitArr[i];
            i -= lowbit(i);
        }
        return ans;
    }

};

void func() {
    int a[10] = {6,7,8,9,1,2,3,4,5,0};
    SegmentTree segmentTree(a, 10);
    cout << "query1 : " << segmentTree.query(segmentTree.getRoot(), 2, 3) << endl;
    cout << "query2 : " << segmentTree.query(segmentTree.getRoot(), 0, 3) << endl;
    cout << "query3 : " << segmentTree.query(segmentTree.getRoot(), 6, 8) << endl;

    BinaryIndexTree binaryIndexTree(a, 10);
    cout << "binIndex1 : " << binaryIndexTree.getSum(3) << endl;
}


#endif //ONLINEJUDGE_SEGMENT_TREE_H

