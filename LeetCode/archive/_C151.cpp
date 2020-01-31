#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int stardandWords(string &s) {
        bool flag = true;
        int t = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (flag && s[i] == ' ') {
                continue;
            }
            flag = false;
            if (s[i] == ' ') {
                flag = true;
            }
            s[t++] = s[i];
        }
        while (t>0 && s[t-1] == ' ') {
            t--;
        }
        s[t] = 0;
        return t;
    }

    void reverseWords(string &s) {
        int t = stardandWords(s);
        s = s.substr(0, t);
        reverse(s.begin(), s.end());
        auto iter1 = s.begin();
        int step = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                reverse(iter1, iter1+step);
                iter1 = iter1+step+1;
                step = 0;
                continue;
            }
            if (i == s.size()-1) {
                reverse(iter1, iter1+step+1);
            }
            step += 1;
        }
    }

    int main() {
        string s = "   ";
        reverseWords(s);
        cout<<s<<endl;
    }
};

