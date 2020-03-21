//
// Created by fangding on 2020-03-20.
//

#ifndef ONLINEJUDGE__C023_H
#define ONLINEJUDGE__C023_H

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (0 == sequence.size()) {
            return false;
        }
        return VerifySquenceOfBST(sequence, 0, sequence.size()-1);
    }
    bool VerifySquenceOfBST(vector<int> &sequence, int start, int end) {
        if (end - start < 2) {
            return true;
        }
        int i = end - 1;
        while (i >= start) {
            if (sequence[i] < sequence[end]) {
                break;
            }
            --i;
        }
        for (int j = i; j >= start; --j) {
            if (sequence[j] > sequence[end]) {
                return false;
            }
        }
        return VerifySquenceOfBST(sequence, start, i) && VerifySquenceOfBST(sequence, i+1, end-1);
    }
};

void func() {
    Solution solution;
    vector<int> sequence{4,6,5,11,17,15,16};
    cout << solution.VerifySquenceOfBST(sequence) << endl;
}

#endif //ONLINEJUDGE__C023_H
