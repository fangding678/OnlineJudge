#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        int i, j, t;
        vector<vector<int>> dpv(len1+1, vector<int>(len2+1, 0));
        t = 0;
        for(i=0; i<=len1; ++i) {
            dpv[i][0] = t++;
        }
        t = 0;
        for(i=0; i<=len2; ++i) {
            dpv[0][i] = t++;
        }
        for(i=1; i<=len1; ++i) {
            for(j=1; j<=len2; ++j) {
                if(word1[i-1] == word2[j-1]) {
                    dpv[i][j] = min(dpv[i-1][j-1], min(dpv[i-1][j], dpv[i][j-1]) + 1);
                }
                else {
                    dpv[i][j] = min(dpv[i-1][j-1], min(dpv[i-1][j], dpv[i][j-1])) + 1;
                }
            }
        }
        return dpv[len1][len2];
    }
};

int func()
{
    string s1 = "algorithm";
    string s2 = "altruistic";
    Solution S;
    cout<<S.minDistance(s1, s2)<<endl;
    return 0;
}
