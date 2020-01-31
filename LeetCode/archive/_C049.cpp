#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        vector<vector<string>> vec;
        for(auto s : strs) {
            string ss = s;
            sort(ss.begin(), ss.end());
            if(m.count(ss)) {
                m[ss].push_back(s);
            }
            else {
                vector<string> vs;
                vs.push_back(s);
                m.insert(unordered_map<string, vector<string>>::value_type(ss, vs));
            }
        }
        for(unordered_map<string, vector<string>>::iterator it = m.begin(); it != m.end(); ++it) {
            sort(it->second.begin(), it->second.end());
            vec.push_back(it->second);
        }
        return vec;
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
