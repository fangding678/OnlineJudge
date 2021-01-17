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
        int len = citations.size();
        int left = 0, right = len - 1;
        int mid;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (citations[mid] >= len - mid) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if (left == len - 1 && citations[left] < 1) {
            left += 1;
        }
        return len - left;
    }
};

void func() {
    Solution solution;
    vector<int> v1{0,1,3,5,6,7};
    vector<int> v2{0, 0, 1};
    vector<int> v3{};
    vector<int> v4{0, 0, 0};
    vector<int> v5{2, 3, 3};
    cout << solution.hIndex(v1) << endl;
    cout << solution.hIndex(v2) << endl;
    cout << solution.hIndex(v3) << endl;
    cout << solution.hIndex(v4) << endl;
    cout << solution.hIndex(v5) << endl;
}

