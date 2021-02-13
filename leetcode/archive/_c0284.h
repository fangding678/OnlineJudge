//
// Created by fangding on 2020-02-01.
//

#include <string>
#include <vector>
#include "__debug"
using namespace std;


class Iterator {
private:
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);

    // Returns the next element in the iteration.
    int next();

    // Returns true if the iteration has more elements.
    bool hasNext() const;
};

class PeekingIterator : public Iterator {
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.

    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        if (hasNext()) {
            Iterator it(*this);
            return it.next();
        }
        return NULL;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        return Iterator::next();
    }

    bool hasNext() const {
        return Iterator::hasNext();
    }
};

void func() {
    string str = "ads";
    cout << str << endl;
}

