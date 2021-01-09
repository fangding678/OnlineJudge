//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        int cnt[256] = {0};
        for (auto c : s) {
            ++cnt[c+128];
        }
        for (auto c : t) {
            --cnt[c+128];
        }
        for (int i = -128; i < 128; ++i) {
            if (cnt[i+128] != 0) {
                return false;
            }
        }
        return true;
    }
};

void func() {
    Solution solution;
    string s1 = "anagram";
    string t1 = "nagaram";
    string s2 = "ads";
    string t2 = "ads";
    cout << solution.isAnagram(s1, t1) << endl;
    cout << solution.isAnagram(s2, t2) << endl;
}

