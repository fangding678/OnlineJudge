//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
using namespace std;

class Solution {
public:

    void mergeArr(vector<int> &nums, vector<int> &tmpNums, vector<int> &ans, vector<int> &indexArr, vector<int> &tmpIndexArr, int s, int m, int e) {
        if (s == m || m == e) {
            return ;
        }
        int m1 = (s+m) / 2;
        mergeArr(tmpNums, nums, ans, tmpIndexArr, indexArr, s, m1, m);
        int m2 = (m+e) / 2;
        mergeArr(tmpNums, nums, ans, tmpIndexArr, indexArr, m, m2, e);
        int i = s, j = m, k = s;
        while(i < m && j < e) {
            if (tmpNums[i] <= tmpNums[j]) {
                tmpIndexArr[k] = indexArr[i];
                ans[indexArr[i]] += j - m;
                nums[k++] = tmpNums[i++];
            } else {
                tmpIndexArr[k] = indexArr[j];
                nums[k++] = tmpNums[j++];
            }
        }
        while(i < m) {
            tmpIndexArr[k] = indexArr[i];
            ans[indexArr[i]] += e - m;
            nums[k++] = tmpNums[i++];
        }
        while(j < e) {
            tmpIndexArr[k] = indexArr[j];
            nums[k++] = tmpNums[j++];
        }
    }

    vector<int> countSmaller(vector<int>& nums) {
        int len = nums.size();
        vector<int> ans(len, 0);
        vector<int> indexArr(len, 0);
        vector<int> tmpIndexArr(len, 0);
        vector<int> tmpNums(nums);
        for (int i = 0; i < len; ++i) {
            indexArr[i] = i;
            tmpIndexArr[i] = i;
        }
        int mid = len / 2;
        mergeArr(nums, tmpNums, ans, indexArr, tmpIndexArr, 0, mid, len);
        return ans;
    }
};

void func() {
    Solution solution;
    vector<int> vec1{5,2,6,1};
    _print(solution.countSmaller(vec1));
    vector<int> vec2{5,2,3,8,1,7,4,9,6};
    _print(solution.countSmaller(vec2));
    vector<int> vec3{6,1};
    _print(solution.countSmaller(vec3));
    vector<int> vec4{1};
    _print(solution.countSmaller(vec4));
    vector<int> vec5{};
    _print(solution.countSmaller(vec5));
}

