//
// Created by fangding on 2020-03-10.
//

#ifndef ONLINEJUDGE__C001_H
#define ONLINEJUDGE__C001_H

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int t = stack2.top();
        stack2.pop();
        return t;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

void func() {
    Solution solution;
    solution.push(1);
    solution.push(1);
    solution.push(2);
    solution.pop();
}

#endif //ONLINEJUDGE__C001_H
