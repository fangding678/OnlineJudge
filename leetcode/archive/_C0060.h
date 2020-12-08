#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string ans = "123456789";
        int a[10] = {0, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        int i, j, t;
        char c;
        ans = ans.erase(n);
        --k;
        for(i=0; i<n-1; ++i) {
            t = k/a[n-i-1];
            if(t) {
                k -= t * a[n-i-1];
                c = ans[t+i];
                for(j=t+i-1; j>=i; --j) {
                    ans[j+1] = ans[j];
                }
                ans[i] = c;
            }
            if(k == 0) {
                break;
            }
        }
        return ans;
    }
};

int func()
{
    Solution S;
    cout << S.getPermutation(3, 4) << endl;
    return 0;
}
