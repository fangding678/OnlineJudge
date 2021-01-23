//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int t = 0, i = citations.size() - 1;
        while (i >= 0) {
            if (citations[i] < t+1) {
                break;
            }
            ++t;
            --i;
        }
        return t;
    }
};

void func() {
    Solution solution;
    vector<int> v1{3,0,6,1,5};
    vector<int> v2{0, 0, 1};
    cout << solution.hIndex(v1) << endl;
    cout << solution.hIndex(v2) << endl;
}

