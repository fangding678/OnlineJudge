//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
using namespace std;

class Solution {
public:
    void processStr(string &input, vector<char> &opArr, vector<int> &numArr) {
        vector<string> arr;
        size_t start_i = 0;
        size_t end_i = start_i;
        while (end_i < input.size()) {
            if (input[end_i] >= '0' && input[end_i] <= '9') {
                ++end_i;
                continue;
            }
            numArr.push_back(stoi(input.substr(start_i, end_i-start_i)));
            opArr.push_back(input[end_i]);
            start_i = end_i+1;
            end_i = start_i;
        }
        numArr.push_back(stoi(input.substr(start_i)));
    }

    int calcOp(int a, char op, int b) {
        if (op == '+') {
            return a+b;
        } else if (op == '-') {
            return a - b;
        } else {
            return a * b;
        }
    }

    void diffWaysHelper1(vector<char> &opArr, vector<int> &numArr, vector<int> &ans) {
        if (opArr.empty()) {
            ans.push_back(numArr[0]);
        } else {
            int tnum1;
            int tnum2;
            int tnum;
            char op;
            for (int i = 0; i < opArr.size(); ++i) {
                tnum1 = numArr[i];
                tnum2 = numArr[i+1];
                op = opArr[i];
                tnum = calcOp(tnum1, op, tnum2);
                opArr.erase(opArr.begin() + i);
                numArr.erase(numArr.begin()+i+1);
                numArr[i] = tnum;
                diffWaysHelper1(opArr, numArr, ans);
                opArr.insert(opArr.begin()+i, op);
                numArr[i] = tnum1;
                numArr.insert(numArr.begin()+i+1, tnum2);
            }
        }
    }

    vector<int> diffWaysHelper(vector<char> &opArr, vector<int> &numArr) {
        vector<int> ans;
        if (opArr.empty()) {
            ans.push_back(numArr[0]);
        } else {
            vector<char> opTmpArr1;
            vector<int> numTmpArr1;
            vector<char> opTmpArr2(opArr);
            vector<int> numTmpArr2(numArr);
            for (int i = 0; i < opArr.size(); ++i) {
                numTmpArr1.push_back(numArr[i]);
                vector<int> ans1 = diffWaysHelper(opTmpArr1, numTmpArr1);
                opTmpArr2.erase(opTmpArr2.begin());
                numTmpArr2.erase(numTmpArr2.begin());
                vector<int> ans2 = diffWaysHelper(opTmpArr2, numTmpArr2);
                opTmpArr1.push_back(opArr[i]);
                for (auto a1 : ans1) {
                    for (auto a2 : ans2) {
                        ans.push_back(calcOp(a1, opArr[i], a2));
                    }
                }
            }
        }
        return ans;
    }

    vector<int> diffWaysToCompute(string input) {
        vector<char> opArr;
        vector<int> numArr;
//        vector<int> ans;
//        diffWaysHelper1(opArr, numArr, ans);
        processStr(input, opArr, numArr);
        _print(opArr);
        cout << "========================================" << endl;
        _print(numArr);
        vector<int> ans = diffWaysHelper(opArr, numArr);
        return ans;
    }
};

void func() {
    Solution solution;
    _print(solution.diffWaysToCompute("2-1-1"));
    _print(solution.diffWaysToCompute("2*3-4*5"));
}

