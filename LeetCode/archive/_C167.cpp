#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int a = 0, b = numbers.size() - 1;
        while (b > a) {
            if (numbers[a] + numbers[b] == target) {
                break;
            } else if (numbers[a] + numbers[b] > target) {
                b--;
            } else {
                a++;
            }
        }
        res.push_back(a+1);
        res.push_back(b+1);
        return res;
    }
};

