//
// Created by fangding on 2020-03-19.
//

#ifndef ONLINEJUDGE__C020_H
#define ONLINEJUDGE__C020_H

class Solution {
public:
    void push(int value) {
        st.push(value);
        if (st_m.empty()) {
            st_m.push(value);
        } else {
            if (value < st_m.top()) {
                st_m.push(value);
            } else {
                st_m.push(st_m.top());
            }
        }
    }
    void pop() {
        st.pop();
        st_m.pop();
    }
    int top() {
        return st.top();
    }
    int min() {
        return st_m.top();
    }

private:
    stack<int> st;
    stack<int> st_m;
};

void func() {
    Solution solution;
    cout << solution << endl;
}
#endif //ONLINEJUDGE__C020_H
