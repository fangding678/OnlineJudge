//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int pcnt = primes.size();
        vector<int> pvec(pcnt, 0);
        vector<int> ans(n, 0);
        ans[0] = 1;
        for (int i = 1; i < n; ++i) {
            int tmin = primes[0] * ans[pvec[0]];
            for (int j = 1; j < pcnt; ++j) {
                int t = primes[j] * ans[pvec[j]];
                if (t < tmin) {
                    tmin = t;
                }
            }
            for (int j = 0; j < pcnt; ++j) {
                int t = primes[j] * ans[pvec[j]];
                if (t == tmin) {
                    ++pvec[j];
                }
            }
            ans[i] = tmin;
        }
        return ans[n-1];
    }
};

void func() {
    Solution solution;
    vector<int> vec1{2,7,13,19};
    vector<int> vec2{2,3,5};
    cout << solution.nthSuperUglyNumber(12, vec1) << endl;
    cout << solution.nthSuperUglyNumber(1, vec2) << endl;
}

