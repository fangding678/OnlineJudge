#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int ans = 0;
        if (m == 0 || n == 0) {
            return ans;
        }
        int t = m;
        vector<int> v1, v2;
        while (t != 0) {
            v1.push_back(t % 2);
            t /= 2;
        }
        t = n;
        while (t != 0) {
            v2.push_back(t % 2);
            t /= 2;
        }
        if (v1.size() != v2.size()) {
            return ans;
        }
        for (int i = v1.size()-1; i >= 0; --i) {
            if (v1[i] != v2[i]) {
                break;
            }
            if (v1[i] == 1 && v2[i] == 1) {
                ans += pow(2, i);
            }
        }
        return ans;
    }
};

