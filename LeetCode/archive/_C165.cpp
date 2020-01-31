#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> vec1;
        vector<int> vec2;
        istringstream iss1(version1);
        string t;
        while (getline(iss1, t, '.')) {
            vec1.push_back(stoi(t));
        }
        istringstream iss2(version2);
        while (getline(iss2, t, '.')) {
            vec2.push_back(stoi(t));
        }
        int ans = 0;
        int len1 = vec1.size(), len2 = vec2.size(), i = 0;
        while (i < len1 && i < len2) {
            if (vec1[i] > vec2[i]) {
                return  1;
            } else if (vec1[i] < vec2[i]) {
                return  -1;
            }
            ++i;
        }
        if (len1 > len2) {
            while (i < len1) {
                if (vec1[i] != 0) {
                    ans = 1;
                }
                ++i;
            }
        } else if (len1 < len2) {
            while (i < len2) {
                if (vec2[i] != 0) {
                    ans = -1;
                }
                ++i;
            }
        }
        return ans;
    }
};

