#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    bool static cmp(int v1, int v2) {
        bool flag = false;
        if (v1 == v2) {
            return flag;
        }
        stringstream ss;
        ss<<v1;
        string s1 = ss.str();
        ss.str("");
        ss<<v2;
        string s2 = ss.str();
        size_t i = 0, j = 0;
        while (i < s1.size() && i < s2.size()) {
            if (s1[i] < s2[i]) {
                return flag;
            } else if (s1[i] > s2[i]) {
                return !flag;
            }
            ++i;
        }
        if (i < s1.size()) {
            while (i < s1.size()) {
                if (s1[i] < s1[j]) {
                    return flag;
                } else if (s1[i] > s1[j]) {
                    return !flag;
                }
                ++i;
                ++j;
            }
            if (s1[i-1] < s1[j]) {
                return flag;
            }
        } else {
            while (i < s2.size()) {
                if (s2[i] < s2[j]) {
                    return !flag;
                } else if (s2[i] > s2[j]) {
                    return flag;
                }
                ++i;
                ++j;
            }
            if (s2[i-1] < s2[j]) {
                return !flag;
            }
        }
        return flag;
    }
    string largestNumber(vector<int>& nums) {
        string ans = "";
        sort(nums.begin(), nums.end(), cmp);
        stringstream stream;
        for (auto num : nums) {
            stream<<num;
            ans += stream.str();
            stream.str("");
        }
        return ans;
    }
};

