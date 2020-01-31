#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        if(strs.size() <= 0)
            return res;
        size_t i, j;
        size_t len = strs[0].size();
        bool mark = false;
        for(i=1; i<strs.size(); ++i) {
            if (strs[i].size() < len) {
                len = strs[i].size();
            }
        }
        for(i=0; i<len; ++i) {
            for(j=1; j<strs.size(); ++j) {
                if(strs[0][i] != strs[j][i]) {
                    mark = true;
                    break;
                }
            }
            if(mark) {
                break;
            }
            res += strs[0][i];
        }
        return res;
    }
};

int func()
{
    Solution S;
    vector<string> strs{"", "sdhgerha"};
    cout<<S.longestCommonPrefix(strs)<<endl;
    return 0;
}
