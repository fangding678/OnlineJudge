//
// Created by fangding on 2020-02-02.
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
#include <sstream>
#include <cmath>
#include <utility>
#include <unordered_map>
#include <memory.h>
#include <codecvt>
#include <locale>
using namespace std;

#ifndef ONLINEJUDGE_UTILS_H
#define ONLINEJUDGE_UTILS_H

template <typename T1>
void _print(vector<T1> v) {
    if (v.size() < 1) {
        cout << "empty arr!" << endl;
        return;
    }
    for (auto i : v) {
        cout << i << "\t";
    }
    cout << endl;
}

template <typename T1>
void _print(vector<vector<T1>> vv) {
    if (vv.size() < 1) {
        cout << "empty two dim arr!" << endl;
        return;
    }
    for (auto &v : vv) {
        _print(v);
    }
    cout << endl;
}

template <typename T1>
void _print(T1 nums, int n) {
    if (n < 1) {
        cout << "empty arr!" << endl;
        return;
    }
    for (int i = 0; i < n; ++i) {
        cout << nums[i] << "\t";
    }
    cout << endl;
}

template <typename T2, typename V2>
void _print(map<T2, V2> &mp) {
    for (auto &m : mp) {
        cout << m.first << ":" << m.second << " ";
    }
    cout << endl;
}

template <typename T3>
void _print(stack<T3> st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

template <typename T3>
void _print(deque<T3> de) {
    while (!de.empty()) {
        cout << de.front() << " ";
        de.pop_front();
    }
    cout << endl;
}

template <typename T4>
void _print(set<T4> st) {
    for (auto s : st) {
        cout << s << " ";
    }
    cout << endl;
}

#endif //ONLINEJUDGE_UTILS_H
