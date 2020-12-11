//
// Created by fangding on 2020-02-01.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int indNum = 26;
typedef struct TrieNode {
    TrieNode() {
        for (int i = 0; i < indNum; ++i) {
            p[i] = nullptr;
        }
        is_leaf = false;
    }
    TrieNode* p[indNum];
    bool is_leaf;
} TrieNode;

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* t = &trieNode;
        for (char c : word) {
            int ind = (int) (c - 'a');
            if (nullptr == t->p[ind]) {
                t->p[ind] = new TrieNode();
            }
            t = t->p[ind];
        }
        t->is_leaf = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        TrieNode* t = &trieNode;
        return search(word, t, 0);
    }

    bool search(string &word, TrieNode* t, int ind) {
        for (int i = ind; i < word.length(); ++i) {
            cout << word[i] << endl;
            if ('.' == word[i]) {
                if (i == word.length() - 1) {
                    for (int j = 0; j < indNum; ++j) {
                        if (t->p[j] && t->p[j]->is_leaf) {
                            return true;
                        }
                    }
                }
                for (int j = 0; j < indNum; ++j) {
                    if (nullptr != t->p[j]) {
                        TrieNode* t1 = t->p[j];
                        if (search(word, t1, i+1)) {
                            return true;
                        }
                    }
                }
                return false;
            } else {
                int k = (int) (word[i] - 'a');
                if (nullptr == t->p[k]) {
                    return false;
                } else {
                    t = t->p[k];
                }
            }
        }
        return t->is_leaf;
    }

    TrieNode trieNode;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

void func() {
    string word = "ads";
    WordDictionary* obj = new WordDictionary();
    obj->addWord(word);
    bool param_2 = obj->search("...");
    cout << param_2 << endl;
}

