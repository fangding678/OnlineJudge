//
// Created by fangding on 2020-07-21.
//

#ifndef ONLINEJUDGE__STOCK_H
#define ONLINEJUDGE__STOCK_H

class Stock {

private:
    struct LinkNode {
        int val;
        LinkNode * next;
    };
    const int INF = DBL_MIN;

public:
    void reverseList(LinkNode *head) {
        if (!head || !head->next) {
            return;
        }
        LinkNode *p = head->next;
        LinkNode *q = p;
        head->next = nullptr;
        while (p) {
            q = p->next;
            p->next = head->next;
            head->next = p;
            p = q;
        }
    }

    double getMaxProfit(vector<double> &nums, int k) {
        int n = nums.size();
        vector<vector<double>> dp0(n+1, vector<double>(k+1, 0));
        vector<vector<double>> dp1(n+1, vector<double>(k+1, 0));
        for (int l = 1; l <= n; ++l) {
            dp1[0][l] = INF;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                dp0[i][j] = Math.max(dp0[i-1][j], dp1[i-1][j-1] + nums[i]);
                dp1[i][j] = Math.max(dp1[i-1][j], dp0[i-1][j-1] - nums[i]);
            }
        }
        dp0[n][k];
    }

    void printTree(TreeNode *t) {
        queue<TreeNode *> q;
        if (!t) return;
        q.push_back(t);
        while(!q.is_empty()) {
            int len = q.size();
            for (int i = 0; i < len; ++i) {
                TreeNode *t = q.pop_front();
                cout << t->val << " ";
                if (t->left) {
                    q.push_back(t->left);
                }
                if (t->right) {
                    q.push_back(t->right);
                }
            }
            cout << endl;
        }
    }

};


void func() {
    vector<double> nums{4,5,2,3,6,7};
    int target = 7;
    Stock stock;
    stock.solution(nums, target);
//    _print(nums);
}

#endif //ONLINEJUDGE__STOCK_H
