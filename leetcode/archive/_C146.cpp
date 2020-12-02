#include <iostream>
#include <unordered_map>
#include <tuple>
#include <list>

using namespace std;

class LRUCache {
public:
    unordered_map<int, tuple<int, list<int>::iterator>> m;
    list<int> used;
    int capacity;
    LRUCache(int capacity): capacity(capacity) {
    }

    int get(int key) {
        if (m.find(key) == m.end()) {
            return -1;
        }
        update_used(key);
        return std::get<0>(m[key]);
    }

    void put(int key, int value) {
        if (m.find(key) == m.end()) {
            if (m.size() >= capacity) {
                m.erase(used.back());
                used.pop_back();
            }
            used.push_front(key);
        } else {
            update_used(key);
        }
        m[key] = make_tuple(value, used.begin());
    }

    void update_used(int key) {
        auto it1 = std::get<1>(this->m[key]);
        used.erase(it1);
        used.push_front(key);
        std::get<1>(m[key]) = used.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

