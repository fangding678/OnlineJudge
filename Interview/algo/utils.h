//
// Created by fangding on 2020-02-02.
//

#ifndef ONLINEJUDGE_UTILS_H
#define ONLINEJUDGE_UTILS_H

template <typename T1>
void _print(vector<T1> v) {
    for (auto i : v) {
        cout << i << " ";
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

template <typename T4>
void _print(set<T4> st) {
    for (auto s : st) {
        cout << s << " ";
    }
    cout << endl;
}

#endif //ONLINEJUDGE_UTILS_H
