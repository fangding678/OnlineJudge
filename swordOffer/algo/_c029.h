//
// Created by fangding on 2020-03-21.
//

#ifndef ONLINEJUDGE__C029_H
#define ONLINEJUDGE__C029_H

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        int len = input.size();
        vector<int> ans;
        if (0 == len || 0 == k || k > len) {
            return ans;
        }
        for (int i = 0; i < k; ++i) {
            ans.push_back(input[i]);
            int l = i;
            int j;
            while (l > 0) {
                j = (l - 1) / 2;
                if (ans[j] < ans[l]) {
                    int tmp = ans[j];
                    ans[j] = ans[l];
                    ans[l] = tmp;
                } else {
                    break;
                }
                l = j;
            }
        }
        for (int i = k; i < len; ++i) {
            if (input[i] < ans[0]) {
                ans[0] = input[i];
                int j = 0;
                while (2*j+1 < k) {
                    if (2*j+2 >= k) {
                        if (ans[j] < ans[2*j+1]) {
                            int tmp = ans[j];
                            ans[j] = ans[2*j+1];
                            ans[2*j+1] = tmp;
                            j = 2*j+1;
                        } else {
                            break;
                        }
                    } else {
                        if (ans[j] < ans[2*j+1] && ans[2*j+1] > ans[2*j+2]) {
                            int tmp = ans[j];
                            ans[j] = ans[2*j+1];
                            ans[2*j+1] = tmp;
                            j = 2*j+1;
                        } else if (ans[j] < ans[2*j+2] && ans[2*j+1] < ans[2*j+2]) {
                            int tmp = ans[j];
                            ans[j] = ans[2*j+2];
                            ans[2*j+2] = tmp;
                            j = 2*j+2;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
        return ans;
    }
};

void func() {
    Solution solution;
    vector<int> vec{4,5,1,6,2,7,3,8};
    vector<int> ans = solution.GetLeastNumbers_Solution(vec, 7);
    _print(ans);
}

#endif //ONLINEJUDGE__C029_H
