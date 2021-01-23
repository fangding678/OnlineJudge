//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
using namespace std;

// 利用四平方和定理：任何一个整数都可以表示为不超过4个数的平方和
// 推论：当且仅当n=4^a(8b+7)时，n恰好可以表示为4个数的平方和

class Solution {
public:
    int numSquares(int n) {
        while (n % 4 == 0) n /= 4;
        if (n % 8 == 7) return 4;
        for (int i = 0; i * i < n; ++i) {
            int j = pow(n - i*i, 0.5);
            if (j*j + i*i == n) {
                return !!i + !!j;
            }
        }
        return 3;
    }
};

void func() {
    Solution solution;
    cout << solution.numSquares(12) << endl;
    cout << solution.numSquares(15) << endl;
}

