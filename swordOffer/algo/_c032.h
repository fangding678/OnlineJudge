//
// Created by fangding on 2020-03-29.
//

#ifndef ONLINEJUDGE__C032_H
#define ONLINEJUDGE__C032_H

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        sort(numbers.begin(), numbers.end(), cmp);
        string ans = "";
        for (auto num : numbers) {
            ans += to_string(num);
        }
        return ans;
    }

    bool static cmp(int a, int b) {
        string s1 = to_string(a);
        string s2 = to_string(b);
        return s1 + s2 < s2 + s1;
    }
};

void func() {
    Solution solution;
//    vector<int> vec{3,32,321};
    vector<int> vec{3,5,1,4,2};
    cout << solution.PrintMinNumber(vec) << endl;
}

#endif //ONLINEJUDGE__C032_H
