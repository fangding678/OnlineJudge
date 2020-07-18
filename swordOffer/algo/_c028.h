//
// Created by fangding on 2020-03-21.
//

#ifndef ONLINEJUDGE__C028_H
#define ONLINEJUDGE__C028_H

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (0 == numbers.size()) {
            return 0;
        } else if (1 == numbers.size()) {
            return numbers[0];
        }
        int ans = numbers[0];
        int cnt = 1;
        for (int i = 1; i < numbers.size(); ++i) {
            if (ans == numbers[i]) {
                ++cnt;
            } else {
                --cnt;
                if (cnt < 0) {
                    ans = numbers[i];
                    cnt = 1;
                }
            }
        }
        cnt = 0;
        for (auto n : numbers) {
            if (n == ans) {
                ++cnt;
            }
        }
        if (cnt * 2 > numbers.size()) {
            return ans;
        }
        return 0;
    }
};

void func() {
    Solution solution;
    vector<int> numbers{1,1,2,2,2,2,5,4,2,1};
    cout << solution.MoreThanHalfNum_Solution(numbers) << endl;
}

#endif //ONLINEJUDGE__C028_H
