//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans = 0;
        vector<int> flag(words.size(), 0);
        for (int i = 0; i < words.size(); ++i) {
            for(auto w : words[i]) {
                flag[i] |= 1 << (w - 'a');
            }
        }
        for (int i = 0; i < words.size(); ++i) {
            for (int j = i+1; j < words.size(); ++j) {
                if ((flag[i] & flag[j]) == 0) {
                    int tmp = words[i].length() * words[j].length();
                    ans = max(ans, tmp);
                }
            }
        }
        return ans;
    }
};

void func() {
    Solution solution;
    vector<string> vec1{"abcw","baz","foo","bar","xtfn","abcdef"};
    vector<string> vec2{"a","ab","abc","d","cd","bcd","abcd"};
    vector<string> vec3{"a","aa","aaa","aaaa"};
    cout << solution.maxProduct(vec1) << endl;
    cout << solution.maxProduct(vec2) << endl;
    cout << solution.maxProduct(vec3) << endl;
}

