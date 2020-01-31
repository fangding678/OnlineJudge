#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if(words.size() == 0)
            return ans;
        int wordSize = words[0].size();
        size_t i;
        size_t totalSize = words.size() * wordSize;
        unordered_map<string, int> m;
        if(s.size() < totalSize)
            return ans;
        for(auto w : words) {
            m[w]++;
        }
        for(i=0; i<=s.size()-totalSize; ++i) {
            if(isOk(s, m, wordSize, totalSize, i))
                ans.push_back(i);
        }
        return ans;
    }
    bool isOk(string & s, unordered_map<string, int> & m, int wordSize, size_t totalSize, size_t i) {
        unordered_map<string, int> mw;
        string ts;
        for(size_t j=i; j<i+totalSize; j+=wordSize) {
            ts = s.substr(j, wordSize);
            if(m.count(ts) == 0)
                return false;
            mw[ts]++;
            if(mw[ts] > m[ts])
                return false;
        }
        return true;
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
