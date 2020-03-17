//
// Created by fangding on 2020-03-10.
//

#ifndef ONLINEJUDGE__C001_H
#define ONLINEJUDGE__C001_H

class Solution {
public:
    int minNumberInRotateArray(vector<int>& rotateArray) {
        int len = rotateArray.size();
        if (0 == len) {
            return 0;
        }
        int start = 0, end = len-1;
        if (start >= end) {
            return rotateArray[start];
        }
        int mid = 0;
        while (start < end) {
            if (rotateArray[start] < rotateArray[end]) {
                return rotateArray[start];
            }
            mid = (start + end) >> 2;
            if (rotateArray[mid] < rotateArray[end]) {
                end = mid;
            } else if (rotateArray[mid] > rotateArray[start]) {
                start = mid + 1;
            } else {
                ++start;
            }
        }
        return rotateArray[start];
    }
};

void func() {
    Solution solution;
    vector<int> rotateArray{6501,6828,6963,7036,7422,7674,8146,8468,8704,8717,9170,9359,9719,9895,9896,9913,9962,154,293,334,492,1323,1479,1539,1727,1870,1943,2383,2392,2996,3282,3812,3903,4465,4605,4665,4772,4828,5142,5437,5448,5668,5706,5725,6300,6335};
    cout << solution.minNumberInRotateArray(rotateArray) << endl;
}

#endif //ONLINEJUDGE__C001_H
