#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int len = words.size();
        int i, j, t, z, y;
        vector<string> ans;
        string s;
        i=0, j=0, t=-1;
        while(i < len) {
            if(t + 1 + words[i].size() > maxWidth) {
                if(i-1 == j) {
                    string stt(maxWidth - words[j].size(), ' ');
                    s += words[j] + stt;
                }
                else {
                    z = (maxWidth - t)/(i-j-1);
                    y = (maxWidth - t)%(i-j-1);
                    string st(z+1, ' ');
                    while(j < i-1) {
                        if(y > 0) {
                            s += words[j] + st + ' ';
                            --y;
                        }
                        else {
                            s += words[j] + st;
                        }
                        ++j;
                    }
                    s += words[j];
                }
                ans.push_back(s);
                s = "";
                t = -1;
                j = i;
            }
            else {
                t += words[i].size() + 1;
                ++i;
            }
        }
        while(j < i-1) {
            s += words[j] + ' ';
            ++j;
        }
        s += words[j];
        string str(maxWidth - s.size(), ' ');
        s += str;
        ans.push_back(s);
        return ans;
    }
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
