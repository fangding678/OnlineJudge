#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <tuple>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        bool flag = false;
        if ((numerator > 0 && denominator < 0) || (numerator < 0 && denominator > 0)) {
            flag = true;
        }
        long long numerator_t = numerator;
        long long denominator_t = denominator;
        numerator_t = (numerator_t >= 0 ? numerator_t : 0 - numerator_t);
        denominator_t = (denominator_t >=0 ? denominator_t : 0 - denominator_t);
        long long a = numerator_t / denominator_t;
        long long b = numerator_t % denominator_t;
        string ans = "";
        if (flag) {
            ans += "-";
        }
        ans += to_string(a);
        if (b == 0) {
            return ans;
        }
        ans += ".";
        vector<tuple<int, int>> res;
        string ans_dec = "";
        set<int> s;
        s.insert(b);
        long long t;
        while (b != 0) {
            b *= 10;
            t = b;
            if (s.find(b) != s.end()) {
                break;
            }
            res.push_back(make_tuple(b/denominator_t, b));
            s.insert(b);
            b %= denominator_t;
        }
        if (b != 0) {
            for (int i=0; i < res.size(); ++i) {
                int x, y;
                tie(x, y) = res[i];
                if (y == t) {
                    ans_dec += "(";
                }
                ans_dec += to_string(x);
            }
            ans_dec = ans_dec + ")";
        } else {
            for (int i=0; i < res.size(); ++i) {
                ans_dec += to_string(get<0>(res[i]));
            }
        }
        ans += ans_dec;
        return ans;
    }
};

