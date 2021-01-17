//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
using namespace std;

class Solution {
public:
    string smallNumToWords(int num) {
        string ans = "";
        if (num >= hundred) {
            ans += m[num / hundred] + " Hundred ";
            num %= hundred;
        }
        if (num < 1) {
            if (ans.empty()) {
                ans = m[num] + " ";
            }
        } else if (num < 20) {
            ans += m[num] + " ";
        } else {
            int t = num / 10;
            int tt = t * 10;
            ans += m[tt] + " ";
            t = num % 10;
            if (t > 0) {
                ans += m[t] + " ";
            }
        }
        return ans;
    }
    string numberToWords(int num) {
        string ans = "";
        if (num >= billion) {
            ans += smallNumToWords(num / billion) + "Billion ";
            num %= billion;
        }
        if (num >= million) {
            ans += smallNumToWords(num / million) + "Million ";
            num %= million;
        }
        if (num >= thousand) {
            ans += smallNumToWords(num / thousand) + "Thousand ";
            num %= thousand;
        }
        if (num > 0 || ans.empty()) {
            ans += smallNumToWords(num);
        }
        size_t len = ans.size();
        while (len > 0 && ans[len-1] == ' ') --len;
        ans = ans.substr(0, len);
        return ans;
    }

private:
    int billion = 1000 * 1000 * 1000;
    int million = 1000 * 1000;
    int thousand = 1000;
    int hundred = 100;
    map<int, string> m{{0, "Zero"}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"},
                       {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"},
                       {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"},
                       {14, "Fourteen"},{15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"},
                       {18, "Eighteen"}, {19, "Nineteen"},
                       {20, "Twenty"},{30, "Thirty"}, {40, "Forty"}, {50, "Fifty"},
                       {60, "Sixty"},{70, "Seventy"}, {80, "Eighty"}, {90, "Ninety"},
    };

};

void func() {
    Solution solution;
    cout << solution.numberToWords(1) << endl;
    cout << solution.numberToWords(10) << endl;
    cout << solution.numberToWords(34) << endl;
    cout << solution.numberToWords(100) << endl;
    cout << solution.numberToWords(101) << endl;
    cout << solution.numberToWords(1010) << endl;
    cout << solution.numberToWords(1234567891) << endl;
    cout << solution.numberToWords(123100012) << endl;
}

