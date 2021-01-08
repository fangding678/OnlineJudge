//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
using namespace std;

class Solution {
public:
    vector<string> processStr(string &input) {
        vector<string> arr;
        int start_i = 0;
        int end_i = start_i;
        while (end_i < input.size()) {
            if (input[end_i] >= '0' && input[end_i] <= '9') {
                ++end_i;
                continue;
            }
            arr.push_back(input.substr(start_i, end_i-start_i));
            arr.push_back(input.substr(end_i, 1));
            start_i = end_i+1;
            end_i = start_i;
        }
        arr.push_back(input.substr(start_i));
        return arr;
    }
    int calc_op(int a, string &op, int b) {
        if (op == "+") {
            return a+b;
        } else if (op == "-") {
            return a - b;
        } else {
            return a * b;
        }
    }
    vector<int> diffWaysToComputeHelper(vector<string> &arr, int start_i) {
        int count = arr.size() - start_i;
        vector<int> anst;
        if (count <= 0) {
            return anst;
        } else if (count == 1) {
            anst.push_back(stoi(arr[start_i]));
            return anst;
        } else if (count == 3) {
            string op = arr[start_i+1];
            anst.push_back(calc_op(stoi(arr[start_i]), arr[start_i+1], stoi(arr[start_i+2])));
            return anst;
        }
        vector<int> bn1 = diffWaysToComputeHelper(arr, start_i+2);
        int a = stoi(arr[start_i]);
        for (int b : bn1) {
            anst.push_back(calc_op(a, arr[start_i+1], b));
        }
        vector<int> bn2 = diffWaysToComputeHelper(arr, start_i+4);
        a = calc_op(stoi(arr[start_i]), arr[start_i+1], stoi(arr[start_i+2]));
        for (int b : bn2) {
            anst.push_back(calc_op(a, arr[start_i+3], b));
        }
        return anst;
    }

    vector<int> diffWaysToCompute(string input) {
        vector<string> arr = processStr(input);
        _print(arr);
        vector<int> ans = diffWaysToComputeHelper(arr, 0);
        return ans;
    }
};

void func() {
    Solution solution;
    _print(solution.diffWaysToCompute("2-1-1"));
    _print(solution.diffWaysToCompute("2*3-4*5"));
}

