//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        map<char, int> m;
        for (int i = 0; i < secret.size(); ++i) {
            if (secret[i] == guess[i]) {
                bulls += 1;
            } else if (m.find(secret[i]) == m.end()) {
                m[secret[i]] = 1;
            } else {
                m[secret[i]] += 1;
            }
        }
        for (int i = 0; i < secret.size(); ++i) {
            if (secret[i] == guess[i]) {
                continue;
            }
            if (m.find(guess[i]) != m.end() && m[guess[i]] > 0) {
                cows += 1;
                m[guess[i]]--;
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};

void func() {
    Solution solution;
    cout << solution.getHint("1807", "7810") << endl;
    cout << solution.getHint("1123", "0111") << endl;
    cout << solution.getHint("11", "10") << endl;
    cout << solution.getHint("1122", "1222") << endl;
}

