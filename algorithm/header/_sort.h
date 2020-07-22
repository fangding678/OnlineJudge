//
// Created by fangding on 2020-07-18.
//

#ifndef ONLINEJUDGE__SORT_H
#define ONLINEJUDGE__SORT_H

void test1() {
    int nums[50];
    cout << rand() << endl;
    for (int i = 0; i < 50; ++i) {
        nums[i] = rand() % 500;
    }
    _print(nums, 50);
}

#endif //ONLINEJUDGE__SORT_H
