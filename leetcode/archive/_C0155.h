#include <iostream>
#include <stack>

using namespace std;


class MinStack {
private:
    stack<int> stack1;
    stack<int> stack2;

public:
    /** initialize your data structure here. */

    MinStack() {
w
    }

    void push(int x) {
        stack1.push(x);
        if (stack2.empty()) {
            stack2.push(x);
        } else {
            stack2.push(min(x, stack2.top()));
        }
    }

    void pop() {
        stack1.pop();
        stack2.pop();
    }

    int top() {
        return stack1.top();
    }

    int getMin() {
        return stack2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
