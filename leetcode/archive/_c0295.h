//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        if (left_queue.empty()) {
            left_queue.push(num);
            return;
        } else if (right_queue.empty()) {
            if (num < left_queue.top()) {
                right_queue.push(left_queue.top());
                left_queue.pop();
                left_queue.push(num);
            } else {
                right_queue.push(num);
            }
            return;
        }
        int left = left_queue.top();
        if (num >= left) {
            if (left_queue.size() > right_queue.size()) {
                right_queue.push(num);
            } else {
                if (num <= right_queue.top()) {
                    left_queue.push(num);
                } else {
                    left_queue.push(right_queue.top());
                    right_queue.pop();
                    right_queue.push(num);
                }
            }
        } else {
            if (left_queue.size() > right_queue.size()) {
                right_queue.push(left_queue.top());
                left_queue.pop();
            }
            left_queue.push(num);
        }

    }

    double findMedian() {
        if (left_queue.size() > right_queue.size()) {
            return left_queue.top();
        }
        return (left_queue.top() + right_queue.top()) / 2.0;
    }

private:
    priority_queue<int> left_queue;
    priority_queue<int, vector<int>, greater<int>> right_queue;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

void func() {
    string str = "ads";
    cout << str << endl;
}

