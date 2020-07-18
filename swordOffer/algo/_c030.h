//
// Created by fangding on 2020-03-21.
//

#ifndef ONLINEJUDGE__C030_H
#define ONLINEJUDGE__C030_H

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if (array.size() == 0) {
            return 0;
        }
        int len = array.size();
        int ans = array[0], tmp = array[0];
        for (int i = 1; i < len; ++i) {
            if (tmp > 0) {
                tmp = tmp + array[i];
            } else {
                tmp = array[i];
            }
            ans = max(ans, tmp);
        }
        return ans;
    }
};

void func() {
    Solution solution;
//    vector<int> array{6,-3,-2,7,-15,1,2,2};
    vector<int> array{-6,-3,-2,-7,-15,-1,-2,-2};
    cout << solution.FindGreatestSumOfSubArray(array) << endl;
}

#endif //ONLINEJUDGE__C030_H
