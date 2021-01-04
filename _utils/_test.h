//
// Created by fangding on 2020-07-18.
//
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <utility>
#include <unordered_map>
#include "_debug.h"
#include "_struct_utils.h"

using namespace std;

#ifndef ONLINEJUDGE__SORT_H
#define ONLINEJUDGE__SORT_H

void test1() {
    int nums[50];
    cout << rand() << endl;
    for (int i = 0; i < 50; ++i) {
        nums[i] = rand() % 500;
    }
    _print(nums, 50);
}

void test_struct() {
    vector<int> vList1{2,3,4};
    vector<int> vTree1{3,5,1,6,2,0,8,-1,-1,7,4};
    List list = List(vList1);
    list.print();
    Tree tree = Tree(vTree1);
    tree.printPreOrder();
}

#endif //ONLINEJUDGE__SORT_H
