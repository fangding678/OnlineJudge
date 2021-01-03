//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int len = nums.size();
        int cnt = len / 3;
        int a1, a2, cnt1 = 0, cnt2 = 0;
        bool flag1 = false, flag2 = false;
        for (auto n : nums) {
            if (!flag1) {
                if (flag2 && a2 == n) {
                    ++cnt2;
                } else {
                    a1 = n;
                    cnt1 = 1;
                    flag1 = true;
                }
            } else if (!flag2) {
                if (n != a1) {
                    a2 = n;
                    cnt2 = 1;
                    flag2 = true;
                } else {
                    cnt1 += 1;
                }
            } else {
                if (a1 == n) {
                    cnt1 += 1;
                } else if (a2 == n) {
                    cnt2 += 1;
                } else {
                    if (cnt1 > 1 && cnt2 > 1) {
                        --cnt1;
                        --cnt2;
                    } else if (cnt1 > 1) {
                        flag2 = false;
                        --cnt1;
                    } else if (cnt2 > 1) {
                        flag1 = false;
                        --cnt2;
                    } else {
                        flag1 = false;
                        flag2 = false;
                    }
                }
            }
            cout << a1 << ":" << cnt1 << ":" << flag1 << "\t" << a2 << ":" << cnt2 << ":" << flag2 << endl;
        }
        cnt1 = 0, cnt2 = 0;
        for (auto n : nums) {
            if (n == a1) {
                cnt1 += 1;
            } else if (n == a2) {
                cnt2 += 1;
            }
        }
        if (cnt1 > cnt) {
            ans.push_back(a1);
        }
        if (cnt2 > cnt) {
            ans.push_back(a2);
        }
        cout << "===" << a1 << "\t" << a2 << endl;
        return ans;
    }
};

void func() {
    Solution solution;
    vector<int> v1{3,2,3};
    vector<int> v2{1,1,1,3,3,2,2,2};
    vector<int> v3{1};
    vector<int> v4{1,1,1,2,3,7,8,1,6,9};
    vector<int> v5{2,1,1,3,1,4,5,6};
    vector<int> v6{4,1,2,3,4,4,3,2,1,4};
    _print(solution.majorityElement(v1));
    _print(solution.majorityElement(v2));
    _print(solution.majorityElement(v3));
    _print(solution.majorityElement(v4));
    _print(solution.majorityElement(v5));
    _print(solution.majorityElement(v6));
}

