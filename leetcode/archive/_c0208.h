//
// Created by fangding on 2020-01-31.
//


#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int Count = 26;

typedef struct Node {
    Node *head[Count];
    bool isEnd;
    Node():isEnd(false) {
        for (int i = 0; i < Count; ++i) {
            head[i] = nullptr;
        }
    }
} Node;

class Trie {
private:
    Node root;
public:
    /** Initialize your data structure here. */
    Trie() {}

    /** Inserts a word into the trie. */
    void insert(string word) {
        auto ph = root.head;
        int len = word.size();
        for (int i = 0; i < len; ++i) {
            int ind = (int) (word[i] - 'a');
            if (!ph[ind]) {
                ph[ind] = new Node();
            }
            if (i == len-1) {
                ph[ind]->isEnd = true;
            }
            ph = ph[ind]->head;
        }
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto pn = &root;
        for (auto c : word) {
            int ind = (int) (c - 'a');
            if (nullptr == pn->head[ind]) {
                return false;
            } else {
                pn = pn->head[ind];
            }
        }
        return pn->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto pn = &root;
        for (auto c : prefix) {
            int ind = (int) (c - 'a');
            if (!pn->head[ind]) {
                return false;
            } else {
                pn = pn->head[ind];
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

void func() {
    Trie trie;
    Trie *tmp = &trie;
    tmp = new Trie();

    trie.insert("a");
    bool r0 = trie.search("a");   // returns true
    cout << "r0=" << r0 << endl;
    trie.insert("apple");
    bool r1 = trie.search("apple");   // returns true
    cout << "r1=" << r1 << endl;
    bool r2 = trie.search("app");     // returns false
    cout << "r2=" << r2 << endl;
    bool r3 = trie.startsWith("app"); // returns true
    cout << "r3=" << r3 << endl;
    trie.insert("app");
    bool r4 = trie.search("app");     // returns true
    cout << "r4=" << r4 << endl;
}

