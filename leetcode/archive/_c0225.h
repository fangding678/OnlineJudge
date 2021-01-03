//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        data.push_front(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x = data.front();
        data.pop_front();
        _print(data);
        return x;
    }

    /** Get the top element. */
    int top() {
        return data.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return data.empty();
    }

private:
    deque<int> data;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

void func() {
    MyStack* obj = new MyStack();
    int x = 1;
    obj->push(x);
    int param_2 = obj->pop();
    int param_3 = obj->top();
    bool param_4 = obj->empty();
    cout << param_2 << "\t" << param_3 << "\t" << param_4 << endl;
}

