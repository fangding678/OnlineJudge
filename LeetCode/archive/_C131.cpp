#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<string>> ans;
    int len;
public:
    vector<vector<string>> partition(string s) {
        ans.clear();
        len = s.size();
        if(len == 0) {
            return ans;
        }
        vector<string> vec;
        partitionCore(vec, s, 0);
        return ans;
    }
    void partitionCore(vector<string> &vec, string &s, int i) {
        for(int j = i; j<len; ++j){
            if(isCheck(s, i, j)) {
                vec.push_back(s.substr(i, j-i+1));
                if(j == len-1) {
                    ans.push_back(vec);
                }
                else {
                    partitionCore(vec, s, j+1);
                }
                vec.pop_back();
            }
        }
    }
    bool isCheck(string &s, int low, int high) {
        while(low<high) {
            if(s[low] != s[high]) {
                return false;
            }
            ++low;
            --high;
        }
        return true;
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
