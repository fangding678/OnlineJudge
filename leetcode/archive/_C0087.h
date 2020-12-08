#include <iostream>
#include <string>
#include <cstring>

using namespace std;

// leetcode, Interleaving String
// ���棬ʱ�临�Ӷ�O(n^3)���ռ临�Ӷ�O(n^3)
class Solution1 {
public:
    bool isScramble(string s1, string s2) {
        const int N = s1.size();
        if (N != s2.size()) return false;
        // f[n][i][j]����ʾ����Ϊn�����Ϊs1[i]��
        // ���Ϊs2[j]�����ַ����Ƿ�Ϊscramble
        bool f[N + 1][N][N];
        fill_n(&f[0][0][0], (N + 1) * N * N, false);

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                f[1][i][j] = (s1[i] == s2[j]);

        for (int n = 1; n <= N; ++n) {
            for (int i = 0; i + n <= N; ++i) {
                for (int j = 0; j + n <= N; ++j) {
                    for (int k = 1; k < n; ++k) {
                        if ((f[k][i][j] && f[n - k][i + k][j + k]) ||
                                (f[k][i][j + n - k] && f[n - k][i + k][j])) {
                            f[n][i][j] = true;
                            break;
                        }
                    }
                }
            }
        }
        return f[N][0][0];
    }
};

class Solution {
private:
    const int N = 256;
public:
    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size()) {
            return false;
        }
        if(s1 == s2) {
            return true;
        }
        int len = s1.size();
        int a[N], i;
        memset(a, 0, N*sizeof(int));
        for(i=0; i<len; ++i) {
            ++a[s1[i]];
            --a[s2[i]];
        }
        for(i=0; i<N; ++i) {
            if(a[i] != 0) {
                return false;
            }
        }
        for(i=1; i<len; ++i) {
            if((isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                isScramble(s1.substr(i), s2.substr(i))) ||
               ((isScramble(s1.substr(0, i), s2.substr(len-i)) &&
                isScramble(s1.substr(i), s2.substr(0, len-i))))) {
                    return true;
                }
        }
        return false;
    }
};

int func()
{
    Solution S;
    cout <<S.isScramble("great", "rgeat")<< endl;
    return 0;
}
