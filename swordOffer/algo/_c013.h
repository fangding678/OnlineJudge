//
// Created by fangding on 2020-03-17.
//

#ifndef ONLINEJUDGE__C013_H
#define ONLINEJUDGE__C013_H

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int len = array.size();
        if (len <= 1) {
            return;
        }
        int t1 = len-1;
        int t2 = t1;
        int tlen = len;
        while (t1 >= 0) {
            if (1 == array[t1]%2) {
                array.push_back(array[t1]);
            } else {
                if (t1 != t2) {
                    array[t2] = array[t1];
                }
                --t2;
            }
            --t1;
        }
        while (t2 >= 0) {
            array[t2] = array[tlen];
            --t2;
            ++tlen;
        }
        array.erase(array.begin()+len, array.end());
    }
};

void func() {
    Solution solution;
//    vector<int> arr{2,1,5,3,4,6};
    vector<int> arr{4,2,6};
    _print(arr);
    solution.reOrderArray(arr);
    _print(arr);
}

#endif //ONLINEJUDGE__C013_H
