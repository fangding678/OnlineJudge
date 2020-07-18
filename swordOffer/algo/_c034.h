//
// Created by fangding on 2020-03-29.
//

#ifndef ONLINEJUDGE__C034_H
#define ONLINEJUDGE__C034_H


class Solution {
public:
    int charToIndex(char c) {
        if (c >= 'A' && c <= 'Z') {
            return c - 'A';
        } else {
            return c - 'a' + 26;
        }
    }
    int FirstNotRepeatingChar(string str) {
        int arr[55] = {0};
        for (char c : str) {
            int index = charToIndex(c);
            ++arr[index];
        }
        int len = str.length();
        for (int i = 0; i < len; ++i) {
            int index = charToIndex(str[i]);
            if (1 == arr[index]) {
                return i;
            }
        }
        return -1;
    }
};

void func() {
    Solution solution;
    cout << solution.FirstNotRepeatingChar("sdgdgsfhdwshf") << endl;
}

#endif //ONLINEJUDGE__C034_H
