#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string s[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void letterCombinationsCore(vector<string> & res, string & digits, string & str, size_t i) {
        if(i == digits.size()) {
            res.push_back(str);
            return ;
        }
        int k = digits[i] - '0';
        for(size_t j=0; j<s[k].size(); ++j) {
            str[i] = s[k][j];
            letterCombinationsCore(res, digits, str, i+1);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.size() == 0)
            return res;
        string str(digits.size(), ' ');
        letterCombinationsCore(res, digits, str, 0);
        return res;
    }
};

int func()
{
    Solution S;
    string digits = "23";
    vector<string> strs = S.letterCombinations(digits);
    for(size_t i=0; i<strs.size(); ++i) {
        cout<<strs[i]<<endl;
    }
    return 0;
}
