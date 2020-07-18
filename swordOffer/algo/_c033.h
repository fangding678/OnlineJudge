//
// Created by fangding on 2020-03-29.
//

#ifndef ONLINEJUDGE__C033_H
#define ONLINEJUDGE__C033_H

class Solution {
public:
    int minT(int a, int b, int c) {
        return min(min(a, b), c);
    }
    int GetUglyNumber_Solution(int index) {
        vector<int> uglyArr;
        uglyArr.push_back(1);
        int p1 = 0, p2 = 0, p3 = 0;
        for (int i = 1; i < index; ++i) {
            int tmp = minT(uglyArr[p1]*2, uglyArr[p2]*3, uglyArr[p3]*5);
            if (tmp == uglyArr[p1]*2) {
                ++p1;
            }
            if (tmp == uglyArr[p2]*3) {
                ++p2;
            }
            if (tmp == uglyArr[p3]*5) {
                ++p3;
            }
            uglyArr.push_back(tmp);
        }
        return uglyArr[index-1];
    }
};

void func() {
    Solution solution;
    cout << solution.GetUglyNumber_Solution(7) << endl;
}

#endif //ONLINEJUDGE__C033_H
