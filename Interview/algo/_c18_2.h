//
// Created by fangding on 2020-02-02.
//

#ifndef ONLINEJUDGE__C18_2_H
#define ONLINEJUDGE__C18_2_H

class NextElement {
public:
    vector<int> findNext(vector<int> A, int n) {
        vector<int> res(A.size(), -1);
        if (1 >= n) {
            return res;
        }
        stack<int> st;
        st.push(0);
        for (int i = 1; i < A.size(); ++i) {
            while (!st.empty() && A[i] > A[st.top()]) {
                res[st.top()] = A[i];
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()) {
            res[st.top()] = -1;
            st.pop();
        }
        return res;
    }
};

void func() {
    cout << "running begin..." << endl;
    vector<int> A{11,13,10,5,12,21,3};
    NextElement nextElement;
    _print(A);
    _print(nextElement.findNext(A, 7));
    cout << "running end..." << endl;
}

#endif //ONLINEJUDGE__C18_2_H
