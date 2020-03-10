//
// Created by fangding on 2020-03-10.
//
#include <cstdlib>

#ifndef ONLINEJUDGE__C001_H
#define ONLINEJUDGE__C001_H

class Solution {
public:
    void replaceSpace(char *str,int length) {
        int cnt = 0;
        for (int i = 0; i < length; ++i) {
            if (' ' == str[i]) {
                ++cnt;
            }
        }
        for (int i = length-1; i >= 0; --i) {
            if (0 == cnt) {
                break;
            }
            if (' ' == str[i]) {
                str[i + 2*cnt] = '0';
                str[i + 2*cnt - 1] = '2';
                str[i + 2*cnt - 2] = '%';
                --cnt;
            } else {
                str[i + 2*cnt] = str[i];
            }
        }
    }
};

void func() {
    Solution solution;
    char p[30] = "are you ready!    ";
    solution.replaceSpace(p, strlen(p));
}

#endif //ONLINEJUDGE__C001_H
