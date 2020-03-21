//
// Created by fangding on 2020-03-20.
//

#ifndef ONLINEJUDGE__C024_H
#define ONLINEJUDGE__C024_H

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int>> ans;
        stack<TreeNode*> st;
        stack<pair<bool, bool>> status;
        vector<int> path;
        if (!root) {
            return ans;
        }
        TreeNode *p = root, *q;
        st.push(p);
        status.push(make_pair(true, true));
        path.push_back(p->val);
        while (!st.empty()) {
            q = st.top();
//            cout << "q->val : " << q->val << endl;
//            _print(path);
            if (!q->left && !q->right) {
                if (isE(path, expectNumber)) {
                    vector<int> tPath;
                    for (auto v : path) {
                        tPath.push_back(v);
                    }
                    ans.push_back(tPath);
                }
                st.pop();
                status.pop();
                path.pop_back();
            } else if (!q->right) {
                pair<bool, bool> s = status.top();
                if (s.first) {
                    q = q->left;
                    path.push_back(q->val);
                    st.push(q);
                    status.pop();
                    status.push(make_pair(false, false));
                    status.push(make_pair(true, true));
                } else {
                    q = st.top();
                    st.pop();
                    status.pop();
                    path.pop_back();
                }
            } else if (!q->left) {
                pair<bool, bool> s = status.top();
                if (s.second) {
                    q = q->right;
                    path.push_back(q->val);
                    st.push(q);
                    status.pop();
                    status.push(make_pair(false, false));
                    status.push(make_pair(true, true));
                } else {
                    q = st.top();
                    st.pop();
                    status.pop();
                    path.pop_back();
                }
            } else {
                pair<bool, bool> s = status.top();
                if (s.first) {
                    q = q->left;
                    path.push_back(q->val);
                    st.push(q);
                    status.pop();
                    status.push(make_pair(false, true));
                    status.push(make_pair(true, true));
                } else if (s.second) {
                    q = q->right;
                    path.push_back(q->val);
                    st.push(q);
                    status.pop();
                    status.push(make_pair(false, false));
                    status.push(make_pair(true, true));
                } else {
                    q = st.top();
                    st.pop();
                    status.pop();
                    path.pop_back();
                }
            }
        }
        sortArr(ans);
        return ans;
    }

    bool isE(vector<int> &path, int num) {
        for (auto n : path) {
            num -= n;
        }
        return 0 == num;
    }

    void sortArr(vector<vector<int>> &ans) {
        int len = ans.size();
        if (len < 2) {
            return;
        }
        vector<int> t;
        for (int i = 0; i <= len; ++i) {
            for (int j = i+1; j < len; ++j) {
                if (ans[i].size() < ans[j].size()) {
                    t = ans[i];
                    ans[i] = ans[j];
                    ans[j] = t;
                }
            }
        }
    }
};

void func() {
    Solution solution;
    TreeNode t1(10);
    TreeNode t2(5);
    TreeNode t3(12);
    TreeNode t4(4);
    TreeNode t5(7);
    TreeNode *root = &t1, *p;
    root->left = &t2;
    root->right = &t3;
    p = root->left;
    p->left = &t4;
    p->right = &t5;
    vector<vector<int>> ans = solution.FindPath(root, 22);
    cout << "---------" << endl;
    for (vector<int> a : ans) {
        _print(a);
    }
}

#endif //ONLINEJUDGE__C024_H
