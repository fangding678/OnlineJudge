//
// Created by fangding on 2020-03-20.
//

#ifndef ONLINEJUDGE__C021_H
#define ONLINEJUDGE__C021_H

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if (pushV.size() != popV.size()) {
            return false;
        }
        int len = pushV.size();
        stack<int> st;
        int i = 0, j = 0;
        while (i < len && j < len) {
            cout << "i: " << i << ", j: " << j << endl;
            if (!st.empty()) {
                if (st.top() == popV[j]) {
                    st.pop();
                    ++j;
                } else if (pushV[i] == popV[j]) {
                    ++j;
                    ++i;
                } else {
                    st.push(pushV[i]);
                    ++i;
                }
            } else {
                if (pushV[i] == popV[j]) {
                    ++i;
                    ++j;
                } else {
                    st.push(pushV[i]);
                    ++i;
                }
            }
        }
        cout << "i: " << i << ", j: " << j << endl;
        while (j < len) {
            if (popV[j] != st.top()) {
                return false;
            }
            st.pop();
            ++j;
        }
        if (i == j) {
            return true;
        }
        return true;
    }
};

void func() {
    Solution solution;
    vector<int> v1{1,2,3,4,5};
    vector<int> v2{4,5,3,2,1};
    cout << solution.IsPopOrder(v1, v2) << endl;
}

#endif //ONLINEJUDGE__C021_H
