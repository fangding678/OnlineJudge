#include <iostream>
#include <string>
#include <map>

using namespace std;


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        map<char, char> map1;
        map<char, char> map2;
        for (int i = 0; i < s.size(); ++i) {
            if (map1.find(s[i]) == map1.end() && map2.find(t[i]) == map2.end()) {
                map1.insert(pair<int, int>(s[i], t[i]));
                map2.insert(pair<int, int>(t[i], s[i]));
                continue;
            }
            if (map1[s[i]] == t[i] && map2[t[i]] == s[i]) {
                continue;
            }
            return false;
        }
        return true;
    }
};
