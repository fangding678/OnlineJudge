//
// Created by fangding on 2020-07-14.
//

#ifndef ONLINEJUDGE__SIN2_H
#define ONLINEJUDGE__SIN2_H
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <set>
#include<cmath>
using namespace std;

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

class PackSolution {
public:
    const int INF = -1;

    void BST(vector<vector<int>> &path, vector<vector<int>> &ans, vector<int> &nums, int w, vector<int> tmp_vec) {
        if(0 == w) {
            ans.push_back(tmp_vec);
        }
        for (int i = 0; i < w; ++i) {
            if (path[i][w] < 0) {
                continue;
            }
            int index = path[i][w];
            int t_len = tmp_vec.size();
            if (t_len > 0 && nums[index] > tmp_vec[t_len-1]) {
                continue;
            }
            tmp_vec.push_back(nums[index]);
            BST(path, ans, nums, w-nums[index], tmp_vec);
            tmp_vec.pop_back();
        }
    }

    // 排序数组去重
    vector<int> deletedup(vector<int> &arr) {
        vector<int> nums;
        sort(arr.begin(), arr.end());
        nums.push_back(arr[0]);
        int t = arr[0];
        for (int i = 1; i < arr.size(); ++i) {
            if (t != arr[i]) {
                t = arr[i];
                nums.push_back(t);
            }
        }
        return nums;
    }

    // 假设数组全为正数
    vector<vector<int>> findAllPath(vector<int> &arr, int target) {
        vector<vector<int>> ans;
        vector<vector<int>> path(target+1);
        vector<bool> flag(target+1, false);
        vector<int> nums = deletedup(arr);
        int len = nums.size();
        for (vector<int>& vec : path) {
            for (int i = 0; i <= target; ++i) {
                vec.push_back(INF);
            }
        }
        flag[0] = true;
        for (int i = 0; i < len; ++i) {
            int num = nums[i];
            for (int j = 0; j < target; ++j) {
                if (!flag[j]) {
                    continue;
                }
                int prev = j;
                for (int k = j + num; k <= target; k += num) {
                    path[prev][k] = i;
                    flag[k] = true;
                    prev = k;
                }
            }
        }
        for (vector<int> vec : path) {
            _print(vec);
        }
        vector<int> tmp_vec;
        BST(path, ans, nums, target, tmp_vec);

        for (auto& vec : ans) {
            _print(vec);
        }
        return ans;
    }
};


void func() {
    vector<int> nums{4,5,2,3,6,7};
    int target = 7;
    PackSolution packSolution;
    packSolution.findAllPath(nums, target);
//    _print(nums);
}

#endif //ONLINEJUDGE__SIN2_H
